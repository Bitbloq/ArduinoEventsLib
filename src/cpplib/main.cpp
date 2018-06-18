#define fakearduino

#include <iostream>
#include "../test/eventheap.h"

using namespace std;

Heap heap;

void action1();

//DELAY
void action4(){
    cout << "delay 1000" << endl;
    heap.delay(1000);
    heap.insert(action1);
    heap.delay(0);
}

void action3(){
    cout << "action 3" <<endl;
    heap.insert(action4);
}

//DELAY
void action2(){
    cout << "delay 1000" << endl;
    heap.delay(1000);
    heap.insert(action3);
    heap.delay(0);
}

void action1(){
    cout << "action1" << endl;
    heap.insert(action2);
}

int main(){
    //heap.start();
    heap.insert(action1);
    while(true)
        heap.eventloop();

    return 0;
}
