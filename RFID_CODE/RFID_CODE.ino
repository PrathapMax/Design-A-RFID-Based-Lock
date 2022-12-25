@@ -0,0 +1,139 @@
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <SPI.h>
#include <MFRC522.h>
MFRC522 mfrc522(2, 0);  
int statuss = 0;
int out = 0;
#define ON_Board_LED 2  
const char* ssid = "XXXXXXXXXX"; 
const char* password = "xxxxxxxxx"; /
const char* host = "script.google.com";
const int httpsPort = 443;
WiFiClientSecure client; 
String GAS_ID = "AKfycbwnUvyGaSGp88yW_1BA15ZsU405-jiyXZt6E3P2nJjjB0vVTEMKXJEhNORTEt28P3Q1"; //--> spreadsheet script ID
void setup() {
  pinMode(16,OUTPUT);
  Serial.begin(9600);  
  SPI.begin();    
  mfrc522.PCD_Init();  
  delay(1000);
  WiFi.begin(ssid, password); 
  Serial.println(""); 
  pinMode(ON_Board_LED,OUTPUT);
  digitalWrite(ON_Board_LED, HIGH); 
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    digitalWrite(ON_Board_LED, LOW);
    delay(250);
    digitalWrite(ON_Board_LED, HIGH);
    delay(250);
  }
  digitalWrite(ON_Board_LED, HIGH); 
  Serial.println("");
  Serial.print("Successfully connected to : ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  client.setInsecure();
}
void loop() {
  digitalWrite(16,HIGH);
  int t=0;
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  Serial.println();
  Serial.print(" UID tag : ");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println();
  if (content.substring(1) == "13 B7 21 A7") 
  {
    Serial.println(" Access Granted ");
    Serial.println(" Welcome Person 1 ");
    delay(1000);
    Serial.println(" Have FUN ");
    Serial.println();
    statuss = 1;
    t=1;
  }
  else if 
  (content.substring(1) == "40 7F E8 1B")
  {
    Serial.println(" Access Granted ");
    Serial.println(" Welcome Person 2 ");
    delay(1000);
    Serial.println(" Have FUN ");
    Serial.println();
    statuss = 1;
    t=2;
  }
  else if 
  (content.substring(1) == "F3 2C A2 A7") 
  {
    Serial.println(" Access Granted ");
    Serial.println(" Welcome Person 3");
    delay(1000);
    Serial.println(" Have FUN ");
    Serial.println();
    statuss = 1;
    t=3;
  }
  else if 
  (content.substring(1) == "90 43 AA 22") 
  {
    Serial.println(" Access Granted ");
    Serial.println(" Welcome Person 4");
    delay(1000);
    Serial.println(" Have FUN ");
    Serial.println();
    statuss = 1;
    t=4;
  }
  else   {
    Serial.println(" Access Denied ");
    delay(3000);
    t=0;
  }
  while(t!=0){
    sendData(t);
  delay(5000);
  digitalWrite(16,LOW);
  delay(5000);
  t=0;
  }}
void sendData(int tem) {
  Serial.println("==========");
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }
  String string_temp =  "Person"+ String(tem);
  // String string_temperature =  String(tem, DEC); 
  String url = "/macros/s/" + GAS_ID + "/exec?temperature=" + string_temp;
  Serial.print("requesting URL: ");
  Serial.println(url);
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
         "Host: " + host + "\r\n" +
         "User-Agent: BuildFailureDetectorESP8266\r\n" +
         "Connection: close\r\n\r\n");
  Serial.println("request sent");
} 
