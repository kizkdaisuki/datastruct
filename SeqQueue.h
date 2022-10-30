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
    q.length = 0;

    return OK;
};

Status Push(SeqQueue& q, int x){ 
    if(q.tail - q.head >= q.length - 2) // 扩容
    {
        q.base = (ElementType*)malloc(SeqQueue_SIZE * sizeof (ElementType));
    }
    *(++ q.tail) = x;
    q.length ++ ;
    return OK;
}

ElementType Pop(SeqQueue& q){
    if(q.head > q.tail)
        return ERROR;
    q.length -- ;
    return *(q.head ++);
    
}

Status IsEmpty(SeqQueue q){
    if(q.head > q.tail)
        return OK; // empty 
    return ERROR;
}

ElementType Front(SeqQueue q){

    if(q.head > q.tail)
    {
        printf("queue is empty\n");
        return ERROR;
    }

    return *q.head;
}

Status ClearQueue(SeqQueue& q){
    q.head = q.base;
    q.tail = q.base;
    q.head ++ ;
    q.length = 0;
}
ElementType GetSize(SeqQueue q){
    return q.length;
}

void testqueue(){
    SeqQueue s;
    InitSeqQueue(s);
    for(int i = 1; i <= 10; i ++) 
        Push(s, i);
    printf("size = %d\n", GetSize(s));
    printf("%d\n", Front(s));
    Pop(s);
    printf("size = %d\n", GetSize(s));
    printf("%d\n", Front(s));
    ClearQueue(s);
    printf("size = %d\n", GetSize(s));
    printf("%d\n", IsEmpty(s));
    printf("%d\n", Front(s));
}