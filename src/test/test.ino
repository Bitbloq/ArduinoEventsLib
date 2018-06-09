#include "eventheap.h"

#include <BQZUMJunior.h>
#include <BQZUMJuniorPorts.h>


Heap heap;

BQ::ZUMJunior zumJunior;


const uint8_t boton1Pin = BQ::ZUMJunior::ports[1][0];
const uint8_t boton2Pin = BQ::ZUMJunior::ports[2][0];
const uint8_t ledDoble1WhitePin = BQ::ZUMJunior::ports[3][0];
const uint8_t ledDoble1ColorPin = BQ::ZUMJunior::ports[3][1];



void ledDoble1White_action1(){
  digitalWrite(ledDoble1WhitePin,LOW);
}

void ledDoble1White_action2(){
  digitalWrite(ledDoble1WhitePin,HIGH);
}



void ledDoble1Color_action1(){
  digitalWrite(ledDoble1ColorPin,LOW);
}

void ledDoble1Color_action2(){
  digitalWrite(ledDoble1ColorPin,HIGH);
}


bool boton1ON = false;

void finish_boton1ON(){
 boton1ON = false; 
}

void register_boton1(){
  if(boton1ON) return;
  boton1ON = true;
  heap.start();
  // callbacks ...
  heap.insert(ledDoble1White_action1);
  heap.delay(1000);
  heap.insert(ledDoble1White_action2);
  heap.delay(1000);
  heap.insert(ledDoble1White_action1);
  heap.delay(1000);
  heap.insert(ledDoble1White_action2);
  // end callbacks
  heap.insert(finish_boton1ON);
}



bool boton2ON = false;

void finish_boton2ON(){
 boton2ON = false; 
}

void register_boton2(){
  if(boton2ON) return;
  boton2ON = true;
  heap.start();
  // callbacks ...
  heap.insert(ledDoble1Color_action1);
  heap.delay(500);
  heap.insert(ledDoble1Color_action2);
  heap.delay(500);
  heap.insert(ledDoble1Color_action1);
  heap.delay(500);
  heap.insert(ledDoble1Color_action2);
  heap.delay(500);
  heap.insert(ledDoble1Color_action1);
  heap.delay(500);
  heap.insert(ledDoble1Color_action2);
  // end callbacks
  heap.insert(finish_boton2ON);
}


void setup(){
  zumJunior.setup();
  pinMode(boton1Pin, INPUT);
  pinMode(boton2Pin, INPUT);
  pinMode(ledDoble1WhitePin, OUTPUT);
  pinMode(ledDoble1ColorPin, OUTPUT);
  digitalWrite(ledDoble1WhitePin, HIGH);
  digitalWrite(ledDoble1ColorPin, HIGH);
}

void loop(){


  //loop over all the items and run operations if required
  heap.eventloop();

  if(digitalRead(boton1Pin)) register_boton1();
  if(digitalRead(boton2Pin)) register_boton2();
}
