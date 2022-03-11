#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>
#include <PubSubClient.h>

SoftwareSerial linkSerial(10, 11);

const char * ssid = "CPE-08A6";
const char * password = "9876543210";

const char* mqtt_server = "broker.netpie.io";
const int mqtt_port = 1883;
const char* mqtt_Client = "a13362ef-50eb-4591-a5b0-62bab765f61b";
const char* mqtt_username = "m9zFF4u3jUCAk24maZVpeBid4rzbY3Sa";
const char* mqtt_password = "uQC5vx_qWL~UO~m*!m$tJrMIoOHYIUrj";

WiFiClient espClient;
PubSubClient client(espClient);
WiFiServer server(80);

void reconnect() {
  while (!client.connected()) {
    if (client.connect(mqtt_Client, mqtt_username, mqtt_password)) {

    }
    else {
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print(ssid);


  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.print(WiFi.localIP());
  client.setServer(mqtt_server, mqtt_port);
  server.begin();
}
void loop() {

  StaticJsonDocument<300> doc;
  DynamicJsonDocument data(1024);
  DeserializationError err = deserializeJson(doc, Serial);
  if (err == DeserializationError::Ok)
  {
    if (!client.connected()) {
      reconnect();
    }
    client.loop();

    DynamicJsonDocument rootJson(1024);
    JsonObject dataNode  = rootJson.createNestedObject("data");
    dataNode["left1"] = doc["fsr1"];
    dataNode["left2"] = doc["fsr2"];
    dataNode["left3"] = doc["fsr3"];
    dataNode["right4"] = doc["fsr4"];
    dataNode["right5"] = doc["fsr5"];
    dataNode["right6"] = doc["fsr6"];
    char buffer[1024];
    serializeJson(rootJson, buffer);
    client.publish("@shadow/data/update", buffer);
    WiFiClient wclient = server.available();
    if (!wclient) {
      return;
    }

    while (!wclient.available())
    {
      delay(1);
    }
    String req = wclient.readStringUntil('\r');
    wclient.flush();
    String web = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r \n\r\n";
    web += "<html>\r\n";
    web += "<body>\r\n";
    web += "<img src=>";
    web += "<h1>MY Arduino</h1>\r\n";
    web += "<h2>Arduino ATmega328 NodeMCU ESP8266</h2>\r\n";
    web += "<p>\r\n";
    web += "FSR SENSOR\r\n";

    web += "</p>\r\n";
    web += "\nปลายเท้าขวา: ";
    web += doc["fsr1"].as<int>();
    web += "\r\n";
    web += "<p>\r\n";

    web += "</p>\r\n";
    web += "ส้นเท้าขวา: ";
    web += doc["fsr2"].as<int>();
    web += "\r\n";
    web += "<p>\r\n";

    web += "</p>\r\n";
    web += "กลางเท้าขวา: ";
    web += doc["fsr3"].as<int>();
    web += "\r\n";
    web += "<p>\r\n";

    web += "</p>\r\n";
    web += "ปลายเท้าซ้าย: ";
    web += doc["fsr4"].as<int>();
    web += "\r\n";

    web += "</p>\r\n";
    web += "ส้นเท้าซ้าย: ";
    web += doc["fsr5"].as<int>();
    web += "\r\n";
    web += "<p>\r\n";

    web += "</p>\r\n";
    web += "กลางเท้าซ้าย: ";
    web += doc["fsr6"].as<int>();
    web += "\r\n";


    web += "</body>\r\n";
    web += "</html>\r\n";

    web += "<html>\r\n";
    web += "<body>\r\n";

    web += "<p>\r\n";
    wclient.print(web);


    delay(2000);
  }
  else
  {
    while (linkSerial.available() > 0)
      linkSerial.read();
  }
}
