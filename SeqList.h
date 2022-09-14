#include "head.h" 
#define OK 1
#define ERROR 0
#define SeqList_SIZE 20
typedef int ElementType;
typedef int Status;

typedef struct SeqList{
    ElementType* data;
    int length;
    int MaxSize;
}SeqList;

Status InitSeqList(SeqList& a){
    ElementType* q;
    a.data = (ElementType*)malloc(SeqList_SIZE * sizeof (ElementType));
    q = a.data;
    a.length = 0;
    a.MaxSize = SeqList_SIZE;
    int i = 0;
    for(i = 0; i < 10; i ++)
    {
        *q = i;
        a.length ++ ;
        q ++ ;
    }

    return OK;

}

Status CleaSeqList(SeqList& a){
    if(!a.length)
        return ERROR;
    a.length = 0;
    return OK;
}

Status PrintSeqList(SeqList & a){
    if(!a.length)
    {
        printf("SeqList is empty\n");
        return false;
    }
    int i;
    for(i = 0; i < a.length; i ++)
        printf("%d ", *(a.data + i)); 

    puts("");
    return OK;

}

Status Add(SeqList& a, int idx, int value){
    if(idx < 1 || idx > a.length)
        return ERROR;
    int i;
    for(i = a.length; i > idx; i --)
        a.data[i] = a.data[i - 1];
    a.length ++ ; 
    a.data[i] = value;
    return OK;
}

Status Del(SeqList& a, int idx){
    if(idx < 1 || idx > a.length)
        return ERROR;
    int i;
    for(i = idx; i < a.length; i ++)
        a.data[i] = a.data[i + 1];
    a.length -- ;
    return OK;
}






