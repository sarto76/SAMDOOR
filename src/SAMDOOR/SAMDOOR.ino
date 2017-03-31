/* INCLUDES */
#include <SPI.h>
#include <SD.h>
#include <Ethernet.h>
#include <Wire.h>
#include <DS1307.h>

#define rfidEnable 2
#define sdPin 4
#define doorPin 8

/* VARIABILI GLOBALI */
unsigned long lastConnectionCheckTime = 0;
unsigned long lastTimeUpdateTime = 0;
unsigned long lastRfidUseTime = 0;
boolean isServerReachable = false;
//byte mac[] = { 0x90, 0xA2, 0xDA, 0x10, 0x25, 0xFE }; // mac dell'arduino ethernet
byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x8A, 0xE2 }; // mac dello shield per arduino uno
// IP del server
IPAddress serverIp(192, 168, 1, 10);  
// IP dell'Arduino
IPAddress ip(192, 168, 1, 11);
EthernetClient server;
// SDA A4, SCL A5
DS1307 clock;
// Rfid
int  val = 0; 
int bytesread = 0; 
char code[10]; 
boolean isRfidPaused = false;
// Porta
boolean isDoorOpened = false;
boolean isUserAccessed = false;
/* COSTANTI */
const unsigned long RFID_PAUSE = 6L * 1000L;
const unsigned long POST_INTERVAL = 5L * 1000L;
const unsigned int SERVER_PORT = 80;
// Indica il tempo massimo espresso in millisecondi per la ricezione di una risposta dal server
const unsigned int TIMEOUT_LIMIT = 5000;
const String CONNECTION_CHECK_PATH = "/conncheck.php";
const String TIME_GET_PATH = "/timeupdate.php";
const int RFID_BUFSIZE = 11;
const int RFID_START = 0x0A;
const int RFID_STOP = 0x0D;
// Definisce il nome del file di log
const String LOG_FILE = "logfile.txt";
// Definisce il nome del file dei permessi dell'SD
const String PERMISSIONS_FILE = "permissions.txt";
/* SETUP */
void setup() {
  Serial.begin(2400);
  delay(1000);

  // Initializzazione della rete
  Ethernet.begin(mac, ip);
  
  // Inizializzazione del RTC
  clock.begin();
  if (checkServerConnection()) {
    int date[6];
    getTimeFromServer(date);
    clock.fillByYMD(date[0], date[1], date[2]); 
    clock.fillByHMS(date[3], date[4], date[5]);
    clock.setTime();
  }
  pinMode(2, OUTPUT);
  digitalWrite(rfidEnable, LOW);

  // Inizializzazione SD
  // Controlla che l'SD sia presente e funzionante
  if (!SD.begin(sdPin)) {
    Serial.println(F("SD card failed, or not present"));
  }
  Serial.println(F("SD card initialized."));
  
  // Controlla che esista il file memorizzante i log
  if (SD.exists(LOG_FILE)) {
    Serial.println(LOG_FILE + " exists.");
  } else {
    Serial.println(LOG_FILE + " doesn't exist.");
    // Crea un nuovo file e lo chiude subito
    Serial.println("Creating " + LOG_FILE);
    File f = SD.open(LOG_FILE, FILE_WRITE);
    f.close();
  }
  // Controlla che esista il file memorizzante i permessi
  if (SD.exists(PERMISSIONS_FILE)) {
    Serial.println(PERMISSIONS_FILE + " exists.");
  } else {
    Serial.println(PERMISSIONS_FILE + " doesn't exist.");
    // Crea un nuovo file e lo chiude subito
    Serial.println("Creating " + PERMISSIONS_FILE);
    File f = SD.open(PERMISSIONS_FILE, FILE_WRITE);
    f.close();
  }
  // TODO: Stesso codice di sopra ma per permissions.txt
}

/* LOOP */
void loop() {
  String strBuffer = "";
  // Controlla ogni 10 secondi la connessione con il server collegandosi a /conncheck.php
  if (millis() - lastConnectionCheckTime > POST_INTERVAL) { 
    strBuffer = sendPostRequest(CONNECTION_CHECK_PATH, "");
    // memorizza l'utlima connessione
    lastConnectionCheckTime = millis();
  }
  
  // Controlla se la connessione al database è riuscita 
  if (strBuffer != "") {
    if (strBuffer.indexOf("connection: failed") > 0) {
      Serial.println(F("Connessione con il database fallita"));  
      isServerReachable = false;
    } else if (strBuffer.indexOf("connection: ok") > 0) {
      Serial.println(F("Connessione con il database riuscita"));  
      isServerReachable = true;
    }
    // Stampa della risposta HTTP del server sulla porta seriale (utile al DEBUGGING)
    //Serial.println(strBuffer);
  } else {
    isServerReachable = false;
  }

  // TODO: Scarica permessi dal server
  
  // Ottenimento codice RFID
  String rfidTagId = getTagId();
  // Mette in pausa l'RFID per 3 secondi se è stato azionato senza bloccare l'esecuzione del programma
  if ((lastRfidUseTime > 0) && (millis() - lastRfidUseTime > RFID_PAUSE)) {
    lastRfidUseTime = 0;
    digitalWrite(rfidEnable, LOW); // riabilita l'RFID
  }
  clock.getTime();
  String accessTime = ((String) (clock.year + 2000)) + "-" + clock.month + "-" + clock.dayOfMonth + " " + clock.hour + ":" + clock.minute + ":" + clock.second;
  if (rfidTagId != "") {
    // Se il server/database è raggiungibile, ottieni permessi e scrivi log dal server, altrimenti utilizza SD
    if (isServerReachable) {
      // chiede se può aprire la porta o no e invia log al server
    } else {
      Serial.println("DIOCAN");
      // TODO: chiede se può aprire la porta o no dall'SD e modifica isUserAccessed
      String authUsers = "";
      File permissionsFile = SD.open(PERMISSIONS_FILE, FILE_WRITE);
      Serial.println("DIOCAN2");
      if (permissionsFile) {
        Serial.println("biopane");
        permissionsFile.close();
        permissionsFile = SD.open(PERMISSIONS_FILE, FILE_READ);
        while (permissionsFile.available()) {
          authUsers += permissionsFile.read();
        }
        Serial.println("permessi: " + authUsers);
        // Se l'utente che ha appena acceduto è contenuto nel file con gli utenti abilitati, consenti accesso
        if (authUsers.indexOf(rfidTagId) > 0) {
            Serial.println(F("Accesso consentito"));
        }
        permissionsFile.close();
      } else {
        Serial.println("DIOCAN4");
      }
      // Apre il logfile
      File dataFile = SD.open(LOG_FILE, FILE_WRITE);
      // Se il file è disponibile, scrive il log
      if (dataFile) {
        // converte il mac address da array a stringa
        String macAddr = "";
        for (int i = 0; i < sizeof(mac); i++) macAddr += mac[i];
        // Scrive il log su SD
        String isDoorOpenedTemp = "false";
        if (isDoorOpened) isDoorOpenedTemp = "true";
        String isUserAccessedTemp = "false";
        if (isUserAccessed) isUserAccessedTemp = "true";
        // Il true finale è per la colonna System_offline
        dataFile.println(macAddr + ";" + rfidTagId + ";" + accessTime + ";" + isDoorOpenedTemp + ";" + isUserAccessedTemp + ";true");
        dataFile.close();
        // print to the serial port too:
        Serial.println(macAddr + ";" + rfidTagId + ";" + accessTime + ";" + isDoorOpenedTemp + ";" + isUserAccessedTemp + ";true");
      }
    }
  }
  // resetta la variabile contenente l'id rfid
  rfidTagId = "";
}

// Questo metodo permette di eseguire delle richieste HTTP con il metodo POST, dove "path" indica il percorso della risorsa php da interrogare e "request"
// indica la richiesta POST da inoltrare
// Esempi:  path = "/conncheck.php"
//          request = "variabile1=foo1&variabile2=foo2";
String sendPostRequest(String path, String request) {
  // Chiude la connessione prima di inoltrarne una nuova
  server.stop();
  if (checkServerConnection()) {
    Serial.println(F("connected"));
    server.println(("POST " + path + " HTTP/1.1"));
    server.println(F("Host: 192.168.1.10"));
    server.println(F("User-Agent: Arduino/1.0"));
    server.println(F("Connection: close"));
    server.println(F("Content-Type: application/x-www-form-urlencoded;"));
    server.print(F("Content-Length: "));
    server.println(request.length());
    server.println();
    server.println(request);
    
    // Ciclo di lettura delle risposte dal server
    // Gestisce anche il timout della connessione: in sintesi attende un millisecondo e riesegue il controllo "se il server ha inviato
    // dei dati, leggili e bufferizzali, altrimenti riesegui il controllo fra 1 millisecondo fino a un massimo definito da TIMEOUT_LIMIT"
    // Questo ha risolto molto bene il problema dell'attesa della risposta (quanto bisogna aspettare? 100ms? 200ms? 1000ms? Così si attende solo
    // quanto necessario prevedendo nel contempo un timeout)
    int timeout = 0;
    String strBuffer = "";
    while (strBuffer == "") {
      delay(1);
      timeout++;
      if (timeout < TIMEOUT_LIMIT) {
        while (server.available()) {
          char c = server.read();
          // Concatena i caratteri in una stringa che funge da "buffer"
          strBuffer += c;
        }
      } else {
        Serial.println(F("Timeout della connessione!"));
        return "";
      }
    }
    return strBuffer;
  } else {
    Serial.println(F("connection failed"));
    return "";
  }
}

// Ritorna 1 se la connessione e' riuscita
boolean checkServerConnection() {
  if (server.connect(serverIp, SERVER_PORT)) {
      isServerReachable = true;
  } else {
      isServerReachable = false;
  }
  return isServerReachable;
}

void getTimeFromServer(int timeArray[]) {
  String strBuffer = sendPostRequest("/timeupdate.php", "");
  if (strBuffer != 0) {
    int index = strBuffer.indexOf("T::");
    if (index > 0) {
      index += 3;
      String d = strBuffer.substring(index, strBuffer.length());
      Serial.println("DATA: " + d);
      timeArray[0] = d.substring(0, 4).toInt();
      timeArray[1] = d.substring(4, 6).toInt();
      timeArray[2] = d.substring(6, 8).toInt();
      timeArray[3] = d.substring(8, 10).toInt();
      timeArray[4] = d.substring(10, 12).toInt();
      timeArray[5] = d.substring(12, 14).toInt();
    }
  }
}

String getTagId() {
  if (Serial.available() > 0) {          // if data available from reader 
    if ((val = Serial.read()) == 10) {   // check for header 
      bytesread = 0; 
      while (bytesread < 10) {              // read 10 digit code 
        if (Serial.available() > 0) { 
          val = Serial.read(); 
          if ((val == 10) || (val == 13)) { // if header or stop bytes before the 10 digit reading 
            break;                       // stop reading 
          } 
          code[bytesread] = val;         // add the digit           
          bytesread++;                   // ready to read next digit  
        } 
      } 
      //Serial.println(F("RFID detected"));
      lastRfidUseTime = millis();
      digitalWrite(rfidEnable, HIGH); // disattiva l'RFID
    } 
  }
  String str = "";
  if (bytesread == 10) {
    // Converte l'array di char contente il codice RFID in una stringa
    for (int i = 0; i < sizeof(code); i++) {
      str += code[i];
    }
  }
  bytesread = 0; 
  return str;
}

