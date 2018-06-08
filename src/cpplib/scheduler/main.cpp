#include <iostream>
#include <unistd.h>
#include "eventheap.h"

using namespace std;

int button1ON = false;
int button2ON = false;

void button1_action0(){
  cout << "button 1 - 1" << endl;
}

void button1_action1(){
  cout << "button 1 - 2" << endl;
}

void button2_action0(){
  cout << "button 2 - 1" << endl;
}

void button2_action1(){
  cout << "button 2 - 2" << endl;
}

void button1_action3(){
  button1ON = false;
}

void button2_action3(){
  button2ON = false;
}

int main(){
    Heap heap;
    heap.insert(button1_action0,0);
    heap.insert(button1_action1,1000);
    heap.insert(button1_action0, 2000);
    heap.insert(button1_action1, 3000);
    heap.insert(button1_action0, 4000);
    heap.insert(button1_action1, 5000);
    heap.insert(button2_action0,10);
    heap.insert(button2_action1,100);
    heap.insert(button2_action0, 2000);
    heap.insert(button2_action1, 3500);
    heap.insert(button2_action0, 4000);
    heap.insert(button2_action1, 5050);


    unsigned int timer = 0;

    while(true){
        //loop over all the items and run operations if required
        CallbackItem* it = heap.first;
        while(it!=nullptr){
            CallbackItem* aux = it;
            it = it->next;

            if(aux->timestamp < timer/*current time*/){
                aux->f();
                heap.remove(aux);
            }
        }
        usleep(1000);
        timer++;
    }
}
