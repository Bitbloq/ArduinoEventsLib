#ifndef EVENTHEAP_H
#define EVENTHEAP_H

typedef void (*functionPointer)(void);

class CallbackItem
{
public:
    CallbackItem(functionPointer func, unsigned long t);
    ~CallbackItem();

    unsigned long timestamp;
    functionPointer f;
    CallbackItem* next;
    CallbackItem* prev;

};

class Heap
{
public:
    Heap();
    ~Heap();
    CallbackItem* first;
    void insert(functionPointer, unsigned long);
    void remove(CallbackItem *);
};

#endif // EVENTHEAP_H
