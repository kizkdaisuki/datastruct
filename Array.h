#include "head.h" 

#define mal_arr (Array)malloc(sizeof (struct ArrayNode))
#define OK 1
#define ERROR 0
#define SIZE 20
typedef int ElementType;
typedef int Status;

typedef struct {
    ElementType* data;
    int length;
    int MaxSize;
}Array;

Status InitArray(Array& a){
    ElementType* q;
    a.data = (ElementType*)malloc(SIZE * sizeof (Array));
    q = a.data;
    a.length = 0;
    a.MaxSize = SIZE;
    int i = 0;
    for(i = 0; i < 10; i ++)
    {
        *q = i;
        a.length ++ ;
        q ++ ;
    }

    return OK;

}

Status CleaArray(Array& a){
    if(!a.length)
        return ERROR;
    a.length = 0;
    return OK;
}

Status PrintArray(Array & a){
    int i;
    for(i = 0; i < a.length; i ++)
        printf("%d ", *(a.data + i)); 

    puts("");
    return OK;

}

Status Add(Array& a, int idx, int value){
    if(idx < 1 || idx > a.length)
        return ERROR;
    int i;
    for(i = a.length; i > idx; i --)
        a.data[i] = a.data[i - 1];
    a.length ++ ; 
    a.data[i] = value;
    return OK;
}

Status Del(Array& a, int idx){
    if(idx < 1 || idx > a.length)
        return ERROR;
    int i;
    for(i = idx; i < a.length; i ++)
        a.data[i] = a.data[i + 1];
    a.length -- ;
    return OK;
}






