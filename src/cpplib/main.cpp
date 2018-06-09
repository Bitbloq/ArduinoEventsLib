#define fakearduino

#include <iostream>
#include "../test/eventheap.h"

using namespace std;

/*
void action1(){
    cout << "Action 1" << endl;
}

void action2(){
    cout << "Action 2" << endl;
}

Heap heap;



int main()
{
    heap.start();
    heap.insert(action1);
    heap.delay(1000);
    heap.insert(action2);
    heap.delay(1000);
    //heap.insertIf(if1);
    heap.insert(action1);
    heap.delay(5000);
    heap.insert(action1);


    while(true) heap.eventloop();

    return 0;
}
*/

Heap heap;
bool a = true;

int num = 0;


void action3(){
    cout << "Action 3" << endl;
}

void action21(){
    heap.delay(1000);
    cout << "action21" << endl;
    if(num < 10){
        num++;
        heap.insert(action21);
    }else{
        heap.insert(action3);
    }
}

void action2(){
    heap.delay(1000);
    if (num < 10){
        num++;
        heap.insert(action21);
    }else{
        heap.insert(action3);
    }
}

void action1(){
    cout << "Action 1" << endl;
    heap.insert(action2);
}

int main(){
    heap.start();
    heap.insert(action1);
    while(true)
        heap.eventloop();

    return 0;
}
