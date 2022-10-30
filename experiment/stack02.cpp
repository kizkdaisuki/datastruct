#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


#define OK 1
#define ERROR 0
#define SeqStack_SIZE 10
#define SIZE_DELTA 2
#define mal (Seq)malloc(sizeof (struct SeqStack));
const int Inf = 0x3f3f3f3f;
typedef char ElementType;
typedef int Status;
char ch[100];
typedef struct SeqStack{
    ElementType data;
    struct SeqStack* next;
}*Seq; 

Status InitSeqStack(Seq stack){
    stack->next = NULL;
    return OK;

} 

Status IsEmpty(Seq stack){
    printf("ISm\n");
    return stack->next == NULL ? OK : ERROR;
}

Status Push(Seq& stack, ElementType val){
    printf("push\n");
    Seq p;
    p = mal;
    p->data = val;
    p->next = stack;
    stack = p;
    
}

Status Pop(Seq& stack){
    printf("pop\n");
    Seq s;
    if(!stack) return ERROR;
    s = stack;
    stack = stack->next;
    
}

ElementType Top(Seq stack){
    return stack->data;
}

Status match(char* ch){
    int i = 0;
    Seq s = mal;
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
    printf("%c\n", Top(s));
    return s->next == NULL ? OK : ERROR;
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