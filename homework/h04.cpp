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


typedef struct SeqQueue{
    BiTNode* s[N];
    int hh, tt;
}queue;


int a[N];

Status InitTree(BiTree *T){
    *T = NULL;
    return OK;
}

Status InitQueue(SeqQueue& s){
    s.tt = -1;
    s.hh = 0;
}

Status IsEmpty(SeqQueue s){
    return s.hh > s.tt;
}
Status Push(SeqQueue& q, BiTree t){
    q.s[ ++ q.tt] = t;
}
BiTree Front(SeqQueue& q){
    return q.s[q.hh ++ ];
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

void Print03(BiTree T){
    SeqQueue q;
    InitQueue(q);
    Push(q, T);
    printf("%d ", T->data);
    while (!IsEmpty(q))
    {
        BiTree t = Front(q);
        BiTree l = t->lchild;
        BiTree r = t->rchild;
        if(l)
            printf("%d ", l->data), Push(q, l);
        if(r)
            printf("%d ", r->data), Push(q, r);

    }

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
    puts("PreOrder");][';']
    PreorderPrint(T);
    puts("");
    puts("Inorder");
    InorderPrint(T);
    puts("");
    puts("PostOreder");
    PostorderPrint(T);
    puts("");
    puts("In02");
    Print03(T);
}

int main(){
    solve();
    return 0;
    
}