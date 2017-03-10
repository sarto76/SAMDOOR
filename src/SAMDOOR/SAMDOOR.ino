/* INCLUDES */
#include <SPI.h>
#include <Ethernet.h>

/* VARIABILI GLOBALI */
unsigned long lastConnectionTime = 0;
boolean isServerReachable = false;
byte mac[] = { 0x90, 0xA2, 0xDA, 0x10, 0x25, 0xFE };
IPAddress server(192, 168, 1, 10);  // numeric IP for Google (no DNS)
IPAddress ip(192, 168, 1, 11);
EthernetClient client;

/* COSTANTI */
const unsigned long POST_INTERVAL = 10L * 1000L;
const String CONNECTION_CHECK_PATH = "/conncheck.php";

void setup() {
  // start serial port:
  Serial.begin(9600);
  delay(1000);
  Ethernet.begin(mac, ip);
}

void loop() {
  // Controlla ogni 10 secondi la connessione con il server collegandosi a /conncheck.php
  if (millis() - lastConnectionTime > POST_INTERVAL) {
    sendPostRequest(CONNECTION_CHECK_PATH, "");
    Serial.println("Andale andale");
  }
  // Ciclo di lettura delle risposte dal server
  String strBuffer = "";
  while (client.available()) {
    char c = client.read();
    // Concatena i caratteri in una stringa che funge da "buffer"
    strBuffer += c;
  }
  // Controlla se la connessione è riuscita e setta la variabile isServerReachable
  if (strBuffer != "") {
    // Se il server ritorna connection:failed assegna assegna false a isServerReachable
    isServerReachable = strBuffer.indexOf("connection:failed") > 0;
    // Stampa della risposta HTTP del server sulla porta seriale
    Serial.println(strBuffer);
  }
}

// Questo metodo permette di eseguire delle richieste HTTP con il metodo POST, dove "path" indica il percorso della risorsa php da interrogare e "request"
// indica la richiesta POST da inoltrare
// Esempi:  path = "/conncheck.php"
//          request = "variabile1=foo1&variabile2=foo2";
void sendPostRequest(String path, String request) {
  // close any connection before send a new request.
  client.stop();

  if (checkServerConnection()) {
    Serial.println(F("connected"));
    client.println(("POST " + path + " HTTP/1.1"));
    client.println(F("Host: 192.168.1.10"));
    client.println(F("User-Agent: Arduino/1.0"));
    client.println(F("Connection: close"));
    client.println(F("Content-Type: application/x-www-form-urlencoded;"));
    client.print(F("Content-Length: "));
    client.println(request.length());
    client.println();
    client.println(request);

    // note the time that the connection was made:
    lastConnectionTime = millis();
  } else {
    Serial.println(F("connection failed"));
  }
}
 
// Ritorna 1 se la connessione e' riuscita
int checkServerConnection() {
  return client.connect(server, 80);
}




