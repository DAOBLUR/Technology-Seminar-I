#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>

#include <SoftwareSerial.h>

int counter = 0;
String str;
SoftwareSerial espSerial(4, 0);

const char* ssid = "Familia PIYU";
const char* password = "958919934";


String url = "https://sjh6zkwc-7286.brs.devtunnels.ms/api/ProximitySensor/SetDistance?distance=";

void setup() 
{
  Serial.begin(9600);
  espSerial.begin(9600);

  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}


void loop() 
{
  ReceiveAndSend();
}

void WeatherForecast(String distance)
{
  if (WiFi.status() == WL_CONNECTED) 
  {
    WiFiClientSecure client;
    client.setInsecure();
    
    HTTPClient https;
    String data = distance;
    String fullUrl = url + data;

    Serial.println("Requesting " + fullUrl);

    if (https.begin(client, fullUrl)) 
    {
      int httpCode = https.GET();
      Serial.println("== Response code: " + String(httpCode));
      if (httpCode > 0) 
      {
        Serial.println(https.getString());
      }
      https.end();
    } 
    else 
    {
      Serial.printf("[HTTPS] Unable to connect\n");
    }
  }
}

void ReceiveAndSend() 
{
  str = espSerial.readString();

  Serial.print("espSerial.available = ");
  Serial.print(espSerial.available());
  Serial.print(" - espSerial.readString = ");
  Serial.println(str);

  if(espSerial.available()) 
  {
    str = espSerial.readString();
    Serial.print("Arduino Message: ");
    Serial.println(str);
    Serial.flush();

    WeatherForecast(str);

    espSerial.print("Clean");
  }
  espSerial.print("Clean");
  delay(1025);
}
