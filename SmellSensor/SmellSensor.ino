#include <SoftwareSerial.h>

SoftwareSerial android(6,7);
int MoterPin = 13;

void setup() {
  // put your setup code here, to run once:
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(MoterPin, OUTPUT);

 
 // 両方の電源をオフにする
 digitalWrite(3,LOW); // センサー
 digitalWrite(4,LOW); // ヒーター
 
 android.begin(115200);
 Serial.begin(19200);
// Serial.write("init");
}

void loop() {
  // put your main code here, to run repeatedly:
 int val = 0;
 
 // --- 250ms周期 ---
 // センサーの印加電圧は「ON : 5ms OFF : 245ms」
 // ヒーターの印加電圧は「ON : 8ms OFF : 242ms」
 
 delay(237);
 
 // センサーの電源をオン(5ms)
 digitalWrite(3,HIGH); 
   delay(3);
   // アナログ入力
   val = analogRead(0); 
   delay(2);
 digitalWrite(3,LOW); 
 
 // ヒーターの電源をオン(8ms)
 digitalWrite(4,HIGH); 
   delay(8);
 digitalWrite(4,LOW);  

 
//plot
 Serial.println(val);
 android.print(val);

//from here
  if(android.available()){
    Serial.println(android.read());
  } 

    if(Serial.available()){
    //android.write(Serial.read());
  }
  
//to here

if(val < 840){

 digitalWrite(MoterPin,HIGH); //11番ピンの出力をHIGH = 5Vにする
delay(1000); //1000ミリ秒 = 1秒待つ
digitalWrite(MoterPin,LOW); //11番ピンの出力をLOW = 0Vにする
delay(1000);
}
}
