#include "eventheap.h"
#include <Servo.h>


const byte led1 = 8;
const byte led2 = 6;
const byte led3 = 11;
const byte led4 = 10;
const byte button3 = 2;
const byte button1 = 3;
const byte button2 = 4;
const byte ldr = A5;
const byte ldr2 = A4;


Servo servo;



bool button1ON = false;
bool button2ON = false;
bool button3ON = false;
bool ldrON = false;
bool ldr2ON = false;


void button3_action0(){
  digitalWrite(led3,HIGH);
  digitalWrite(led4,LOW);
}

void button3_action1(){
  digitalWrite(led3,LOW);
  digitalWrite(led4,HIGH);
}

void button3_action3(){
  button3ON = false;
}



void button1_action0(){
  digitalWrite(led1,HIGH);
}

void button1_action1(){
  digitalWrite(led1,LOW);
}

void button2_action0(){
  digitalWrite(led2,HIGH);
}

void button2_action1(){
  digitalWrite(led2,LOW);
}

void button1_action3(){
  button1ON = false;
}

void button2_action3(){
  button2ON = false;
}


void ldr_action0(){
  servo.write(180);
}

void ldr_action1(){
  servo.write(90);
}

void ldr_action2(){
  ldrON = false;
}

Heap heap;


void registerButton1(){
  if (button1ON){
    return;
  }else{
    button1ON = true;
    heap.start();
    heap.insert(button1_action0);
    heap.delay(100);
    heap.insert(button1_action1);
    heap.delay(100);
    heap.insert(button1_action0);
    heap.delay(100);
    heap.insert(button1_action1);
    heap.delay(100);
    heap.insert(button1_action0);
    heap.delay(100);
    heap.insert(button1_action1);
    heap.insert(button1_action3);
  }
}

void registerButton2(){
  if (button2ON){
    return;
  }else{
    button2ON = true;
    heap.start();
    heap.insert(button2_action0);
    heap.delay(500);
    heap.insert(button2_action1);
    heap.delay(500);
    heap.insert(button2_action0);
    heap.delay(500);
    heap.insert(button2_action1);
    heap.delay(500);
    heap.insert(button2_action0);
    heap.delay(500);
    heap.insert(button2_action1);
    heap.insert(button2_action3);
  }
}

void registerButton3(){
  if (button3ON){
    return;
  }else{
    button3ON = true;
        heap.start();
    heap.insert(button3_action0);
    heap.delay(1000);
    heap.insert(button3_action1);
    heap.delay(1000);
    heap.insert(button3_action0);
    heap.delay(1000);
    heap.insert(button3_action1);
    heap.delay(1000);
    heap.insert(button3_action0);
    heap.delay(1000);
    heap.insert(button3_action1);
    heap.insert(button3_action3);
  }
}


void registerLDR(){
  if (ldrON){
    return;
  }else{
    ldrON = true;
    heap.start();
    heap.insert(ldr_action0);
    heap.delay(3000);
    heap.insert(ldr_action1);
    heap.insert(ldr_action2);
  }
}


void setup(){

  pinMode(led1, OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(ldr,INPUT);
  servo.attach(12);
 
}

void loop(){

  if(digitalRead(button1)) registerButton1();
  if(digitalRead(button2)) registerButton2();
  if(digitalRead(button3)) registerButton3();
  if(analogRead(ldr) < 100) registerLDR();

  //loop over all the items and run operations if required
  heap.eventloop();
}
