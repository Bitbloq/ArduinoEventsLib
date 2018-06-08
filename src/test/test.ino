#include <eventheap.h>
#include <Servo.h>


const byte led1 = 8;
const byte led2 = 6;
const byte button1 = 3;
const byte button2 = 4;
const byte ldr = A5;

Servo servo;



bool button1ON = false;
bool button2ON = false;
bool ldrON = false;

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
    heap.insert(button1_action0,millis() + 0);
    heap.insert(button1_action1,millis() + 100);
    heap.insert(button1_action0,millis() + 200);
    heap.insert(button1_action1,millis() + 300);
    heap.insert(button1_action0,millis() + 400);
    heap.insert(button1_action1,millis() + 500);
    heap.insert(button1_action3,millis() + 500);
  }
}

void registerButton2(){
  if (button2ON){
    return;
  }else{
    button2ON = true;
    heap.insert(button2_action0,millis() + 0);
    heap.insert(button2_action1,millis() + 500);
    heap.insert(button2_action0, millis() + 1000);
    heap.insert(button2_action1, millis() + 1500);
    heap.insert(button2_action0, millis() + 2000);
    heap.insert(button2_action1, millis() + 2500);
    heap.insert(button2_action3, millis() + 2500);
  }
}

void registerLDR(){
  if (ldrON){
    return;
  }else{
    ldrON = true;
    heap.insert(ldr_action0, millis() + 0);
    heap.insert(ldr_action1, millis() + 3000);
    heap.insert(ldr_action2, millis() + 3000);
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

  //servo.write(180);

  if(digitalRead(button1)) registerButton1();
  if(digitalRead(button1)) registerButton2();
  if(analogRead(ldr) < 100) registerLDR();

  //loop over all the items and run operations if required
  CallbackItem* it = heap.first;
  while(it!=nullptr){
      CallbackItem* aux = it;
      it = it->next;

      if(aux->timestamp < millis()){
          aux->f();
          heap.remove(aux);
      }
  }
}
