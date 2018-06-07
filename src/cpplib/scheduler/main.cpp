#include <iostream>
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


    //loop over all the items and run operations if required
    CallbackItem* it = first;
    while(it!=nullptr){
        if(it->timestamp > /*current time*/){
            it->f();
            CallbackItem* aux = it;
            it = it->next;
            heap.remove(aux);
        }
    }
}
