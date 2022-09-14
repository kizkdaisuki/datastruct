#include "head.h"

#define OK 1
#define ERROR 0
#define SeqStack_SIZE 10
#define SIZE_DELTA 2
const int Inf = 0x3f3f3f3f;
typedef int ElementType;
typedef int Status;

typedef struct SeqStack{
    ElementType* top;
    ElementType* base;
    int size;
}SeqStack; 

Status InitSeqStack(SeqStack& stack){
    stack.base = (ElementType*)malloc(SeqStack_SIZE  * sizeof (ElementType));
    if(!stack.base)
        return ERROR;
    stack.size = SeqStack_SIZE ;
    
    stack.top = stack.base;

    return OK;

} 

Status IsEmpty(SeqStack& stack){
    if(stack.top == stack.base)
        return true;
    return false;

}

Status Push(SeqStack& stack, int val){
    if(stack.top - stack.base >= stack.size - 2)
    {
        stack.base = (ElementType*)realloc(stack.base, (stack.size * SIZE_DELTA) * sizeof(SeqStack));
        if(!stack.base)
            return ERROR;
        stack.top = stack.base + stack.size - 2;
        stack.size *= SIZE_DELTA;
    }
    * stack.top ++ = val;

    return OK;
}

ElementType Pop(SeqStack& stack){
    if(stack.base == stack.top)
        return Inf;
    return *( -- stack.top);
}

Status Converstion(ElementType x){
    ElementType res = 0;
    SeqStack stack;
    InitSeqStack(stack);
    while(x)
    {
        Push(stack, x % 2);
        x >>= 1;
    }
    while(!IsEmpty(stack))
        printf("%d", Pop(stack));
    puts("");
    return OK;
}