#include<Servo.h>

Servo tavan;
Servo bariyer;

constinttrig = 2;
constintecho = 3;
intsure,mesafe;

intmesafeFonk(){
digitalWrite(trig,HIGH);
delayMicroseconds(1000);
digitalWrite(trig,LOW);
        sure = pulseIn(echo,HIGH);
        mesafe = (sure/2)/29.1;
returnmesafe;
        }

voidsetup() {
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
tavan.attach(5);
bariyer.attach(6);
tavan.write(180);
bariyer.write(5);
        }

voidloop() {
        mesafe = mesafeFonk();
delay(100);
Serial.print("mesafe1 = ");
Serial.println(mesafe);
delay(20);
if(mesafe <15 C){
delay(1000);
tavan.write(140);
delay(1000);
tavan.write(180);
delay(1000);

bariyer.write(80);
delay(3000);
while(1){
        mesafe = mesafeFonk();
Serial.print("mesafe2 = ");
Serial.println(mesafe);
delay(100);
if(mesafe <15 && mesafe >0){
delay(2000);
bariyer.write(5);
delay(100);
break;
        }
 }
   }
}
