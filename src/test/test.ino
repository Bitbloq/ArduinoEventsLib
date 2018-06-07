const byte led1 = 8;
const byte led2 = 6;
const byte button1 = 3;
const byte button2 = 4;


int button1ON = false;
int button2ON = false;

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

int size = 0;
typedef void (*functionPointer)(void);
functionPointer *p = malloc(size * sizeof(functionPointer));
unsigned long * t = malloc(size * sizeof(long));


void registerButton1(){
  if (button1ON){
    return;
  }else{
    button1ON = true;
    functionPointer * tempF = realloc(p, (size + 5) * sizeof(functionPointer) );
    if (tempF != NULL) p = tempF;
    int * tempT = realloc(t, (size + 5) * sizeof(unsigned long));
    if ( tempT != NULL) t = tempT;

    
    *(p + size + 0 ) = button1_action0;
    *(t + size + 0 ) = millis() + 0;
    *(p + size + 1 ) = button1_action1;
    *(t + size + 1 ) = millis() + 1000;
    *(p + size + 2 ) = button1_action0;
    *(t + size + 2 ) = millis() + 2000;
    *(p + size + 3 ) = button1_action1;
    *(t + size + 3 ) = millis() + 3000;
    *(p + size + 4 ) = button1_action3;
    *(t + size + 4 ) = millis() + 3000;

    size += 5;

  }
}

void registerButton2(){
  if (button2ON){
    return;
  }else{
    button2ON = true;
    functionPointer * tempF = realloc(p, (size + 7) * sizeof(functionPointer) );
    if (tempF != NULL) p = tempF;
    int * tempT = realloc(t, (size + 7) * sizeof(int));
    if ( tempT != NULL) t = tempT;

    int t0 = millis();

    *(p + size + 0 ) = button2_action0;
    *(t + size + 0 ) = t0 + 0;
    *(p + size + 1 ) = button2_action1;
    *(t + size + 1 ) = t0 + 100;
    *(p + size + 2 ) = button2_action0;
    *(t + size + 2 ) = t0 + 200;
    *(p + size + 3 ) = button2_action1;
    *(t + size + 3 ) = t0 + 300;
    *(p + size + 4 ) = button2_action0;
    *(t + size + 4 ) = t0 + 400;
    *(p + size + 5 ) = button2_action1;
    *(t + size + 5 ) = t0 + 500;
    *(p + size + 6 ) = button2_action3;
    *(t + size + 6 ) = t0 + 500;


    size += 7;


  }
}


void setup(){

  pinMode(led1, OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
 
}

void loop(){


  if(digitalRead(button1)) registerButton1();
  if(digitalRead(button2)) registerButton2();

  for( int i=0 ; i<(size) ; i++ ){
    if( (millis()) > t[i] ){
      if (p[i]) p[i]();
      p[i] = nullptr;
    } 
  }


}
