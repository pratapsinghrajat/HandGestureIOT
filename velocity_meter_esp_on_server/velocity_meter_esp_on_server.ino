#include<stdlib.h>
#define SSID "TechGalaxyINDIA"
#define PASS "*123TECH#"
#define IP "184.106.153.149" // thingspeak.com
String GET = "GET /update?key=RIL7H21TF3YG33YL&field1=";
#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
const int ir1=8;
const int ir2=9;
char ir1state=0,ir2state=0;
float distance=0,time1=0;
float speed1=0,count=0; 
void setup() {
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  lcd.begin(16, 2);
    lcd.setCursor(0, 0);
  lcd.print(" VELOCITY METER ");
   Serial.begin(9600);
 
  sendDebug("AT");
  delay(2000);
 sendDebug("AT");
  delay(2000);
  delay(3000);
  if(Serial.find("OK")){
    //monitor.println("RECEIVED: OK");
    Serial.println("RECEIVED: OK");
    lcd.clear();
     lcd.setCursor(0, 0);
    lcd.print("connected..");
    delay(2000);
    lcd.clear();
     delay(5000);
    connectWiFi();
    delay(5000);
  }
}
void loop() {
   lcd.setCursor(0, 0);
  lcd.print(" VELOCITY METER ");
  ir1state=digitalRead(ir1);
    ir2state=digitalRead(ir2);
if(ir1state==0)
{
  count=0;
  lcd.setCursor(14,1);
  lcd.print("IN"); 
 do{
  ir1state=digitalRead(ir1);
    ir2state=digitalRead(ir2);
  delayMicroseconds(1);
  count++;
   } while(ir2state==1);
   lcd.setCursor(14,1);
  lcd.print("OT"); 
  time1=count*0.000001;
  speed1=0.010/time1;

  lcd.setCursor(0,1);
  lcd.print(speed1);
  lcd.setCursor(8,1);
   lcd.print("m/s");
  char buffer[10];
  String tempF = dtostrf(speed1, 0, 5, buffer);
  updateTemp(tempF);
 
  }
  
}
void updateTemp(String tenmpF){
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  sendDebug(cmd);
  delay(2000);
  if(Serial.find("Error")){
    //monitor.print("RECEIVED: Error");
    Serial.print("RECEIVED: Error");
    return;
  }
  cmd = GET;
  cmd += tenmpF; 
  cmd += "\r\n";
  Serial.print("AT+CIPSEND=");
  Serial.println(cmd.length());
  if(Serial.find(">")){
   // monitor.print(">");
   // monitor.print(cmd);
    Serial.print(cmd);
  }else{
    sendDebug("AT+CIPCLOSE");
  }
  if(Serial.find("OK")){
   // monitor.println("RECEIVED: OK");
  }else{
   // monitor.println("RECEIVED: Error");
  }
}
void sendDebug(String cmd){
  //monitor.print("SEND: ");
  //monitor.println(cmd);
  Serial.println(cmd);
} 
 
boolean connectWiFi(){
  Serial.println("AT+CWMODE=1");
  delay(2000);
  String cmd="AT+CWJAP=\"";
  cmd+=SSID;
  cmd+="\",\"";
  cmd+=PASS;
  cmd+="\"";
  sendDebug(cmd);
  delay(5000);
  if(Serial.find("OK")){
   // monitor.println("RECEIVED: OK");
    return true;
  }else{
   // monitor.println("RECEIVED: Error");
    return false;
  }
}
