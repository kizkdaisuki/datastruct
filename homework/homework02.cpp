#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define mal_list (List)malloc(sizeof (struct LinkList))
#define OK 1
#define ERROR 0
#define SIZE 20
typedef int ElementType;
typedef int Status;


typedef struct LinkList{
    ElementType val;
    LinkList* next;
}LinkList, *List;



Status InitList(List& l){
    l = mal_list;
    l->next = NULL;
    return OK;

}

Status InsertToHead(List& head, int val){
    List p = mal_list;
    p->val = val;
    p->next = head->next;
    head->next = p;

    return OK;

}

List merge_List(List& l1, List& l2){
    List p = mal_list;
    p->next = NULL;
    while(l1 && l2)
    {
        if(l1->val <= l2->val)
            p->next = l1, l1 = l1->next;
        else
            p->next = l2, l2 = l2->next;
        p = p->next;
    }
    while(l1)
        p->next = l1, l1 = l1->next, p = p->next;
    while(l2)
        p->next = l2, l2 = l2->next, p = p->next;
    List res = mal_list;
    res->next = NULL;
    res->next = p;
    return res;
}


Status PrintList(List list){
    while(list->next)
    {
        list = list->next;
        printf("%d ",list->val);
    }

    puts("");
    return OK;
}


void kizk(){

}


int main (){
    kizk();

    return 0;
}