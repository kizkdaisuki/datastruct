#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define SeqList_SIZE 20
#define mal (BiTree)malloc(sizeof(BiTNode))
const int N = 100010;
typedef int   ElementType;
typedef int Status;
typedef struct BiTNode {
    ElementType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct SeqStack{
    BiTNode* s[N];
    int tt;
}SeqStack; 

typedef struct SeqQueue{
    BiTNode* s[N];
    int hh, tt;
}queue;

Status InitSeqStack(SeqStack& stack){
    stack.tt = -1;
    return OK;

} 

Status IsEmpty(SeqStack& stack){
    return stack.tt == -1;

}

BiTree Push(SeqStack& stack, BiTree val){
    stack.s[ ++ stack.tt ] = val;

}

BiTree Pop(SeqStack& stack){
    stack.tt -- ;
    
}

BiTree Top(SeqStack& stack){
    return stack.s[stack.tt];
}

int a[N];

Status InitTree(BiTree *T){
    *T = NULL;
    return OK;
}

Status InitQueue(SeqQueue& s){
    s.tt = -1;
    s.hh = 0;
}

Status CreateBiTree(BiTree* T, int idx){ 
    if(a[idx] == -1)
        *T = NULL;
    else 
    {
        *T = mal;
        (*T)->data = a[idx];
        CreateBiTree(&(*T)->lchild, idx << 1);
        CreateBiTree(&(*T)->rchild, idx << 1 | 1);
    }
    return OK;
}

void PreorderPrint(BiTree T){
    if(!T)
        return;
    printf("%d ", T->data);
    PreorderPrint(T->lchild);
    PreorderPrint(T->rchild);
}

void InorderPrint(BiTree T){
    if(!T)
        return;
    InorderPrint(T->lchild);
    printf("%d ", T->data);
    InorderPrint(T->rchild);
}

void PostorderPrint(BiTree T){
    if(!T)
        return;
    PostorderPrint(T->lchild);
   
    PostorderPrint(T->rchild);
    printf("%d ", T->data);
}

void InorderPrint02(BiTree Tr){
    SeqStack s;
    BiTree T = Tr;
    InitSeqStack(s);
    // return;
    while(!IsEmpty(s) || T)
    {
        while(T)
        {
            Push(s, T);
            // printf("%d ", Top(s)->data);
            // printf("%d ", s[tt]->data);
            T = T->lchild;
            // return;
        }
        if(!IsEmpty(s))
        {
            T = Top(s);
            Pop(s);
            printf("%d ", T->data);
            T = T->rchild;
        }

    }

}

void Print03(BiTree T){

}


void solve(){
    BiTree T;
    InitTree(&T);
    memset(a, -1, sizeof a);
    int n;
    scanf("%d", &n);
    int i = 1;
    for(; i <= n; i ++)
        scanf("%d", &a[i]);
    CreateBiTree(&T, 1);
    puts("PreOrder");
    PreorderPrint(T);
    puts("");
    puts("Inorder");
    InorderPrint(T);
    puts("");
    puts("PostOreder");
    PostorderPrint(T);
    puts("");
    puts("In02");
    InorderPrint02(T);
}

int main(){
    solve();
    return 0;
    
}