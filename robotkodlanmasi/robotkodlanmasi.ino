#include<Servo.h>
Servo kasa;

constintsagHiz = 5;
constintsolHiz = 6;
constintsolOn = 7;
constintsolArka = 8;
constintsagOn = 9;
constintsagArka = 10;

constinttrigOn=A1;
constintechoOn=A0;
intmesafeOn;

constinttrigArka=2;
constintechoArka=3;
intmesafeArka;

/*constinttrigSol=12;
constintechoSol=4;
intmesafeSol;*/
intsure,mesafe,i=0;
booldebug = true;

constintileri = 1;
constintgeri = 2;
/*constint sol = 3;
constintsag = 4;*/
constintdur = 5;

voidsetup() {
Serial.begin(9600);
kasa.attach(11);
pinMode(trigOn,OUTPUT);
pinMode(echoOn,INPUT);
pinMode(trigArka,OUTPUT);
pinMode(echoArka,INPUT);
/*pinMode(trigSol,OUTPUT);
pinMode(echoSol,INPUT);*/
pinMode(solOn,OUTPUT);
pinMode(solArka,OUTPUT);
pinMode(sagOn,OUTPUT);
pinMode(sagArka,OUTPUT);
pinMode(sagHiz,OUTPUT);
pinMode(solHiz,OUTPUT);
digitalWrite(solOn,LOW);
digitalWrite(solArka,LOW);
digitalWrite(sagOn,LOW);
digitalWrite(sagArka,LOW);
analogWrite(sagHiz,0);
analogWrite(solHiz,0);
kasa.write(0);
        }

intmesafeFront(){
digitalWrite(trigOn,HIGH);
delayMicroseconds(1000);
digitalWrite(trigOn,LOW);
        sure = pulseIn(echoOn,HIGH);
        mesafe = (sure/2)/29.1;
returnmesafe;
        }

intmesafeBack(){
digitalWrite(trigArka,HIGH);
delayMicroseconds(1000);
digitalWrite(trigArka,LOW);
        sure = pulseIn(echoArka,HIGH);
        mesafe = (sure/2)/29.1;
returnmesafe;
        }

/*intmesafeLeft(){
digitalWrite(trigSol,HIGH);
delayMicroseconds(1000);
digitalWrite(trigSol,LOW);
  sure = pulseIn(echoSol,HIGH);
  mesafe = (sure/2)/29.1;
return mesafe;
}*/

voidyon(intdeger,inthiz){
if(deger == 1){//ileri gidis
analogWrite(sagHiz,hiz);
analogWrite(solHiz,hiz);
digitalWrite(sagOn,HIGH);
digitalWrite(solOn,HIGH);
digitalWrite(sagArka,LOW);
digitalWrite(solArka,LOW);
        }
else if(deger == 2){//geri gidis
analogWrite(sagHiz,hiz);
analogWrite(solHiz,hiz);
digitalWrite(sagArka,HIGH);
digitalWrite(solArka,HIGH);
digitalWrite(sagOn,LOW);
digitalWrite(solOn,LOW);
        }
else if(deger == 3){//sola donus
analogWrite(sagHiz,hiz);
analogWrite(solHiz,hiz);
digitalWrite(sagOn,HIGH);
digitalWrite(solArka,LOW);
digitalWrite(sagArka,LOW);
digitalWrite(solOn,LOW);
        }
else if(deger == 4){//sagadonus
analogWrite(sagHiz,hiz);
analogWrite(solHiz,hiz);
digitalWrite(sagArka,HIGH);
digitalWrite(solOn,HIGH);
digitalWrite(sagOn,LOW);
digitalWrite(solArka,LOW);
        }
else if(deger == 5){//durdurma komutu
digitalWrite(sagOn,HIGH);
digitalWrite(sagArka,HIGH);
digitalWrite(solOn,HIGH);
digitalWrite(solArka,HIGH);
delay(500);
analogWrite(sagHiz,hiz);
analogWrite(solHiz,hiz);
digitalWrite(sagOn,LOW);
digitalWrite(sagArka,LOW);
digitalWrite(solOn,LOW);
digitalWrite(solArka,LOW);
delay(50);
        }
delay(50);
        }

voidloop() {
delay(80);
if(i<2){
mesafeOn = mesafeFront();
delay(50);
Serial.print("On = ");
Serial.println(mesafeOn);
delay(20);

if(mesafeOn>13 || mesafe <1){
        yon(ileri,100);
delay(80);
        }
else{
        yon(dur,0);
delay(100);
        i++;
if(i == 1){
while(1){
mesafeOn = mesafeFront();
delay(50);
if(mesafeOn<1){

        }
else if(mesafeOn>13){
break;
        }
        }
        }
else if(i == 2){
delay(1000);
kasa.write(40);
delay(1500);
kasa.write(0);
delay(100);
        }
        }
        }
if(i>1){
mesafeArka = mesafeBack();
Serial.print("Arka = ");
Serial.println(mesafeArka);
delay(50);
if(mesafeArka>10 || mesafe <1){
        yon(geri,100);
delay(80);
        }
else{
        yon(dur,0);
delay(3000);
        i=0;
        }
        }
        }
