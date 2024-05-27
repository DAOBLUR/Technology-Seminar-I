#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>

#include <SoftwareSerial.h>

int counter = 200;
String str;
SoftwareSerial EspSerial(4, 0); // D2 and D3

const char* ssid = "Familia PIYU";
const char* password = "958919934";

const String BaseApiUrl = "https://sjh6zkwc-7286.brs.devtunnels.ms/api/ProximitySensor/";

void WifiClientInitialize()
{
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

void setup() 
{
  Serial.begin(9600);
  EspSerial.begin(9600);
  WifiClientInitialize();
}

void loop() 
{
  ReceiveAndSend();
}

void SendDitance(String distance)
{
  if (WiFi.status() == WL_CONNECTED) 
  {
    WiFiClientSecure client;
    client.setInsecure();
    
    HTTPClient https;
    String data = "SetDistance?distance=" + String(distance.toInt());
    String fullUrl = BaseApiUrl + data;

    Serial.println("Requesting " + fullUrl);

    if (https.begin(client, fullUrl)) 
    {
      https.addHeader("Content-Type", "application/x-www-form-urlencoded");
      
      int httpCode = https.POST("");
      Serial.println("Response code: " + String(httpCode));
      if (httpCode > 0) 
      {
        Serial.println(https.getString());
      }
      https.end();
    } 
    else 
    {
      Serial.println("[HTTPS] Unable to connect\n");
    }
  }
}

void ReceiveAndSend() 
{
  if(EspSerial.available() > 0) 
  {
    str = EspSerial.readString();
    Serial.print("Message: ");
    Serial.println(str);
    SendDitance(str);
    EspSerial.flush();
    
    // Send a response
    EspSerial.println(counter);
    
    if(counter < 300) counter++;
    else counter = 200;
  }
}

/*
#define LED D1
void setup() 
{
  pinMode(LED, OUTPUT); 
}
void loop() 
{
  digitalWrite(LED, HIGH);                     
  delay(1000);            
  digitalWrite(LED, LOW);
  delay(1000);
}
*/