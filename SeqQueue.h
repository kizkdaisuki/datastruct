#include "head.h"

#define OK 1
#define ERROR 0
#define SeqQueue_SIZE 10
#define SIZE_DELTA 2
typedef int ElementType;
typedef int Status;

typedef struct SeqQueue{
    ElementType* head;
    ElementType* tail;
    ElementType* base;
    int length;


}SeqQueue;

Status InitSeqQueue(SeqQueue& q){
    q.base = (ElementType*)malloc( SeqQueue_SIZE * sizeof (ElementType));
    if(!q.base) return ERROR;
    q.head = q.base;
    q.tail = q.base;  
    q.head ++ ;
    q.length = SeqQueue_SIZE;

    return OK;
};

Status Push(SeqQueue& q, int x){ 
    if(q.tail - q.head >= q.length - 2) // 扩容
    {
        q.base = (ElementType*)malloc(SeqQueue_SIZE * sizeof (ElementType));
    }
    *(++ q.tail) = x;
    return OK;
}

Status Pop(SeqQueue& q){
    if(q.head > q.tail)
        return ERROR;
    return *(q.head ++);
    return OK;
    
}

Status IsEmpty(SeqQueue q){
    if(q.head > q.tail)
        return ERROR; // empty 
    return OK;
}


void test(){
    SeqQueue s;
    InitSeqQueue(s);
    for(int i = 1; i <= 10; i ++) 

    printf("%d\n", Pop(s));
    printf("%d\n", Pop(s));
    printf("%d\n", Pop(s));
}