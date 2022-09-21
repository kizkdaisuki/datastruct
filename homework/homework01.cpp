#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>


#define OK 1
#define ERROR 0
#define SeqList_SIZE 20
typedef int ElementType;
typedef int Status;

#define stl srand((int)time(NULL)) 


typedef struct SeqList{
    ElementType* data;
    int length;
    int MaxSize;
}SeqList;


void quick_sort(SeqList& s, int l, int r){
    if(l >= r) return;
    int x = s.data[(l + l) / 2], i = l - 1, j = r + 1;
    while(i < j)
    {
        do i ++ ; while(s.data[i] < x);
        do j -- ; while(s.data[j] > x); 
        if(i < j)
        {
            s.data[i] ^= s.data[j];
            s.data[j] ^= s.data[i];
            s.data[i] ^= s.data[j];
        }
        else 
            quick_sort(s, l, j), quick_sort(s, j + 1, r);

    }
}

void merge_SeqList(SeqList& s1, SeqList& s2){
    int i = 0, j = 0;
    int n = s1.length, m = s2.length;
    while(i < n && j < m)
    {
        if(s1.data[i] <= s2.data[j])
            printf("%d ", s1.data[i ++]);
        else 
            printf("%d ", s2.data[j ++]);
    }
    while(i < n)printf("%d ", s1.data[i ++]);
    while(j < m)printf("%d ", s2.data[j ++]);
    
}


Status InitSeqList(SeqList& a){
    ElementType* q;
    a.data = (ElementType*)malloc(SeqList_SIZE * sizeof (ElementType));
    q = a.data;
    a.length = 0;
    a.MaxSize = SeqList_SIZE;
    int i = 0;
    for(i = 0; i < 10; i ++)
    {
        *q = rand() % 100;
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


void solve(){
    SeqList L1, L2;
    InitSeqList(L1), InitSeqList(L2);
    PrintSeqList(L1), PrintSeqList(L2);
    // printf("%d %d\n", L1.length, L2.length);
    quick_sort(L1, 0, L1.length - 1), quick_sort(L2, 0, L2.length - 1);
    merge_SeqList(L1, L2);

}

int main(){
    stl;
    solve();

    return 0;
}