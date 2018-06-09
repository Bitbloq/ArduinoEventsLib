#define fakearduino

#include <iostream>
#include "../test/eventheap.h"

using namespace std;

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
    heap.insert(action1);
    heap.delay(5000);
    heap.insert(action1);


    while(true) heap.eventloop();

    return 0;
}
