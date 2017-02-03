#include <Ethernet.h>
#include <SPI.h>


byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // mac address
byte ip[] = { 10, 0, 0, 177 }; // ip client
byte server[] = { 127, 0, 0, 1 }; // ip server
int port = 80; // porta

EthernetClient client;

void setup()
{
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
  Serial.println(Ethernet.localIP());
  delay(1000);

  Serial.println("connecting...");

  if (client.connect(server,port)) {
    Serial.println("connected");
    client.println("GET /search?q=arduino HTTP/1.0");
    client.println();
  } else {
    Serial.println("connection failed");
  }
}

void loop()
{
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  if (!client.connected()) {
    Serial.println();
    delay(1000);
    Serial.println("disconnecting.");
    delay(1000);

    client.stop();
  }
}
