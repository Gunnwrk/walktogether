#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>

SoftwareSerial linkSerial(10, 11);

const char * ssid = "CPE-08A6";
const char * password = "9876543210";
WiFiServer server(80);
void setup() 
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
  Serial.println("Connecting...  ");
  Serial.printf("Connection Status: %d\n", WiFi.status());
  
    delay(500);
  }
  {
  Serial.print("Wi-Fi connected."); 
  Serial.print("IP Address : ");
  Serial.println(WiFi.localIP()); 
  }
  server.begin();
}
void loop() 
{
  StaticJsonDocument<300> doc;
  DeserializationError err = deserializeJson(doc, Serial);
  if (err == DeserializationError::Ok) 
  {
    WiFiClient client = server.available();
    if (!client) 
    {
      return;
    }
  
    while (!client.available())
    {
      delay(1);
    }
    String req = client.readStringUntil('\r');
    client.flush();
    String web = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r \n\r\n";
    web += "<html>\r\n";
    web += "<body>\r\n";
    web += "<img src=>";
    web += "<h1>Developing a pressure shoe for stride analysis</h1>\r\n";
    web += "<h2>Faculty of Engineering Srinakharinwirot University</h2>\r\n";
    web += "<p>\r\n";
    web += "RIGHT SIDE\r\n"; //แสดงสถานะร้องเท้าข้างขวา
    
    web += "</p>\r\n";
    web += "\nSensor1: ";
    web += doc["Sensor1"].as<int>();
    web += "\r\n";
    web += "<p>\r\n";
  
    web += "</p>\r\n";
    web += "Sensor2: ";
    web += doc["Sensor2"].as<int>();
    web += "\r\n";
    web += "<p>\r\n";
  
    web += "</p>\r\n";
    web += "Sensor3: ";
    web += doc["Sensor3"].as<int>();
    web += "\r\n";
    web += "<p>\r\n";
    
    web += "LEFT SIDE\r\n"; //แสดงสถานะร้องเท้าข้างซ้าย
    
    web += "</p>\r\n";
    web += "Sensor4: ";
    web += doc["Sensor4"].as<int>();
    web += "\r\n";

    web += "</p>\r\n";
    web += "Sensor5: ";
    web += doc["Sensor5"].as<int>();
    web += "\r\n";
    web += "<p>\r\n";
  
    web += "</p>\r\n";
    web += "Sensor6: ";
    web += doc["Sensor6"].as<int>();
    web += "\r\n";
   
   
    web += "</body>\r\n";
    web += "</html>\r\n";
  
    web += "<html>\r\n";
    web += "<body>\r\n";
    
    web += "<meta http-equiv=\"refresh\" content=\"1\">\r\n";
    web +="<body>\r\n";
    
    web += "<p>\r\n";
    client.print(web);
  } 
  else 
  {
    while (linkSerial.available() > 0)
    linkSerial.read();
  }
}
