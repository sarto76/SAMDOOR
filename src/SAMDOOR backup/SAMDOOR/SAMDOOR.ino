/* INCLUDES */
#include <SPI.h>
#include <Ethernet.h>
#include <Wire.h>
#include <DS1307.h>

/* VARIABILI GLOBALI */
unsigned long lastConnectionCheckTime = 0;
unsigned long lastTimeUpdateTime = 0;
boolean isServerReachable = false;
//byte mac[] = { 0x90, 0xA2, 0xDA, 0x10, 0x25, 0xFE };
byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x8A, 0xE2 };
// IP del server
IPAddress serverIp(192, 168, 1, 10);  
// IP dell'Arduino
IPAddress ip(192, 168, 1, 11);
EthernetClient server;
// SDA A4, SCL A5
DS1307 clock;

/* COSTANTI */
const unsigned long POST_INTERVAL = 5L * 1000L;
const unsigned int SERVER_PORT = 80;
// Indica il tempo massimo espresso in millisecondi per la ricezione di una risposta dal server
const unsigned int TIMEOUT_LIMIT = 5000;
const String CONNECTION_CHECK_PATH = "/conncheck.php";
const String TIME_GET_PATH = "/timeupdate.php";

boolean test = true;

/* SETUP */
void setup() {
  Serial.begin(9600);
  delay(1000);

  // Initializzazione della rete
  Ethernet.begin(mac, ip);
  
  // Inizializzazione del RTC
  clock.begin();
  if (checkServerConnection()) {
    int date[6];
    getTimeFromServer(date);
    //clock.fillByYMD(date[0], date[1], date[2]); 
    //clock.fillByHMS(date[3], date[4], date[5]);
    clock.fillByYMD(2013,1,19);//Jan 19,2013
    clock.fillByHMS(15,28,30);//15:28 30"
    clock.setTime();
  }
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
  // Controlla se la connessione è riuscita e setta la variabile isServerReachable
  if (strBuffer != "") {
    if (strBuffer.indexOf("connection: failed") > 0) {
      isServerReachable = false;
      Serial.println(F("Connessione con il database fallita"));  
    } else if (strBuffer.indexOf("connection: ok") > 0) {
      isServerReachable = true;
      Serial.println(F("Connessione con il database riuscita"));  
    }
    // Stampa della risposta HTTP del server sulla porta seriale
    //Serial.println(strBuffer);
  }
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
int checkServerConnection() {
  return server.connect(serverIp, SERVER_PORT);
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

