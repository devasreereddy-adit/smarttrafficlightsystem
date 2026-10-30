#include <RH_ASK.h>//amplitude shift keying

#include <SPI.h> //serial peripheral interface
unsigned long waitAutoOff=millis();
// DATA PIN to pin 11
 
RH_ASK RF;

String st;
//line1
int red1=4;
int yellow1=3;
int green1=2;
//line2
int red2=7;
int yellow2=6;
int green2=5;
//line3
int red3=10;
int yellow3=9;
int green3=8;
//line4
int red4=A0;
int yellow4=12;
int green4=13;
void setup()

{

   Serial.begin(9600); 
   pinMode(red1,OUTPUT);
   pinMode(yellow1,OUTPUT);
   pinMode(green1,OUTPUT);
   pinMode(red2,OUTPUT);
   pinMode(yellow2,OUTPUT);
   pinMode(green2,OUTPUT);
   pinMode(red3,OUTPUT);
   pinMode(yellow3,OUTPUT);
   pinMode(green3,OUTPUT);
   pinMode(red4,OUTPUT);
   pinMode(yellow4,OUTPUT);
   pinMode(green4,OUTPUT);
   Serial.println("started");
   digitalWrite(green1,LOW);
   digitalWrite(yellow1,LOW);
   digitalWrite(red1,LOW);
   digitalWrite(green2,LOW);
   digitalWrite(yellow2,LOW);
   digitalWrite(red2,LOW);
   digitalWrite(green3,LOW);
   digitalWrite(yellow3,LOW);
   digitalWrite(red3,LOW);
   digitalWrite(green4,LOW);
   digitalWrite(yellow4,LOW);
   digitalWrite(red4,LOW);
    if (!RF.init())

       Serial.println("init failed");

}

void loop()

{
   uint8_t buf[60];

   uint8_t buflen = sizeof(buf);

   Serial.print("Message: "); 
   
        while(RF.recv(buf, &buflen))
      {
         int i; 
      //Serial.println(buflen); 
       char* str=(char*)buf; 
     st=String(str); 
     st=st.substring(0,buflen); 
     waitAutoOff=millis(); 
   }
   
   
   if(st=="a")
     {
      Serial.println(st);
      Serial.println("emergency mode");
     digitalWrite(green1,HIGH);  //turns corresponding lane green light on 
     digitalWrite(red1,LOW);
     digitalWrite(red2,HIGH); //turns lane 2 red on
     digitalWrite(red3,HIGH);//turns lane 3 red om
     digitalWrite(red4,HIGH);//turns  lane 4 red on
     Serial.println(st);   
    
      if(millis()-waitAutoOff>=1000UL){
        st="b";
        Serial.println("reset after 5");
      }
   //  st="b"; 
     }       
     else
    { 
      st="b";
    Serial.println(st); 
         VAC();//traffic lights normal function
    }  
   }
   void VAC(){
  digitalWrite(green1,LOW);
  digitalWrite(7, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(A0, HIGH);
  digitalWrite(4, HIGH);
  delay(5000); // Wait for 1000 millisecond(s)
  digitalWrite(4, LOW); // Wait for 1000 millisecond(s)
  digitalWrite(2, HIGH);
  delay(4000); // Wait for 1000 millisecond(s)
  digitalWrite(2, LOW);
  delay(10);// Wait for 1000 millisecond(s)
  digitalWrite(3,HIGH);
  delay(1000);
  digitalWrite(3,LOW);
  // line 2 started
  digitalWrite(4, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(A0, HIGH);
  digitalWrite(7, HIGH);
  delay(5000); // Wait for 5000 millisecond(s)
  digitalWrite(7, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(5, HIGH);
  delay(4000); // Wait for 1000 millisecond(s)
  digitalWrite(5, LOW);
   digitalWrite(6, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(6, LOW);
  delay(10); // Wait for 10 millisecond(s)
  //line 3 started
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(A0, HIGH);
  digitalWrite(10, HIGH);
  delay(5000); // Wait for 1000 millisecond(s)
  digitalWrite(10, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
 
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(8, HIGH);
  delay(4000); // Wait for 1000 millisecond(s)
  digitalWrite(8, LOW);
  delay(10); 
   digitalWrite(9, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(9, LOW);// Wait for 1000 millisecond(s)
  //line 4 started
  digitalWrite(7, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(A0, HIGH);
  delay(5000); // Wait for 1000 millisecond(s)
  digitalWrite(A0, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(13, HIGH);
  delay(4000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(10);// Wait for 1000 millisecond(s)
  digitalWrite(12, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(12, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}

