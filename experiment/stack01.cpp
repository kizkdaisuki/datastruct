#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


#define OK 1
#define ERROR 0
#define SeqStack_SIZE 10
#define SIZE_DELTA 2
const int Inf = 0x3f3f3f3f;
typedef char ElementType;
typedef int Status;
char ch[100];
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

Status Push(SeqStack& stack, ElementType val){
    * (stack.top ++) = val;

    return OK;
}

ElementType Pop(SeqStack& stack){
    return *( -- stack.top);
}

ElementType Top(SeqStack& stack){
    return *(stack.top - 1);
}

Status match(char* ch){
    int i = 0;
    SeqStack s;
    InitSeqStack(s);
    while(ch[i])
    {
    
        switch(ch[i])
        {
            case '{':
            case '[':
            case '(': Push(s, ch[i]); printf("%c\n", Top(s)); break;
            case '}': if(!IsEmpty(s) && Top(s) == '{')
                      {
                            Pop(s); break;
                      }
                      else 
                        return ERROR;
            case ']': if(!IsEmpty(s) && Top(s) == '[')
                      {
                            Pop(s); break;
                      }
                      else 
                        return ERROR;
            case ')': if(!IsEmpty(s) && Top(s) == '(')
                      {
                            Pop(s); break;
                      }
                      else 
                        return ERROR;


        }
        i ++ ;
    }
    printf("qmt\n");
    return (IsEmpty(s));
}

void solve(){
    scanf("%s", ch);
    printf("%s\n", ch);
    if(match(ch))
        printf("match success\n");
    else 
        printf("match error\n");
    
}

int main(){
    solve();
    return 0;
}