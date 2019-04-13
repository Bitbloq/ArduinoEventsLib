//#define fakearduino

#include "ArduinoEventsLib.h"
#include <Arduino.h>

ActionItem::ActionItem(functionPointer func, unsigned long t):
    timestamp{t},
    f{func},
    next{nullptr},
    prev{nullptr}
{

}

Heap::Heap():
    first{nullptr},
    last{nullptr}
{

}

Heap::~Heap(){

    ActionItem* it = first;
    while(it!=nullptr){
        ActionItem* aux = it->next;
        delete it;
        it=aux;
    }
    first = nullptr;
    last = nullptr;
}


void Heap::insert(functionPointer p, int delay){
    if(last){
        //introduce the new one after last
        ActionItem* cb = new ActionItem(p, millis() + delay);
        last->next = cb;
        last = cb;
    }else{
        //it is the first one
        ActionItem* cb = new ActionItem(p, millis() + delay);
        first = cb;
        last = cb;
    }
}

void Heap::remove(ActionItem *cb){
    //If cb is the first iteam in the heap
    if(cb == first){
        if(cb->next){
            //if cb is NOT de last item in the heap
            first = cb->next;
            first->prev = nullptr;
        }else{
            //cb is the only element in the heap
            first = nullptr;
        }
    }else if (cb == last){
        last = cb->prev;
        last->next = nullptr;
    }else{
        //if cb is NOT the first, nor the last item in the heap
        cb->prev->next = cb->next;
        cb->next->prev = cb->prev;
    }

    delete cb;
}

void Heap::eventloop(){
    ActionItem* it = first;
    while(it!=nullptr){
        ActionItem* aux = it;
        it = it->next;
        if(aux->timestamp < millis()){
            aux->f();
            remove(aux);
        }
    }
}
