#include "head.h"

#define mal_list  (List)malloc(sizeof (struct ListNode))
#define OK 1
#define ERROR 0
typedef int ElementType;
typedef int Status;


typedef struct ListNode{
    ElementType val;
    ListNode* next;
}ListNode, *List;

// 初始化链表
Status InitList(List& list){

    list = mal_list ;
    list->next = NULL;
    return OK;
}
// 尾插
Status InsertToTail(List& list, int value){
    List p, s;
    p = list;
    while(p->next)
        p = p->next;
    s = mal_list ;
    s->next = NULL;
    s->val = value;
    p->next = s;
    return OK;
}
// 头插
Status InsertToHead(List& list, int value){
    List p = mal_list ;
    p->val = value;
    p->next = list->next;
    list->next = p;
    
    return OK;
}
// 删除第idx个点
Status RemoveIndex(List& list, int idx){
    List p = list;
    while(--idx && p)
        p = p->next;
    if(idx)
        return ERROR;
    List temp = p->next;
    p->next = p->next->next;
    free(temp);
    return OK;
}
// 删除值为value的节点
Status RemoveValue(List& _list, int value){
    List list = _list;
    while(list->next)
    {
        if(list->next->val == value)
        {
            list->next = list->next->next;
            return OK;
        }
        else 
            list = list->next;
    }

    return ERROR;
}
// 在第idx个点后面插入value
Status Insert(List& list, int idx, int value){
    List p = list;
    while(idx --)
        p = p->next;
    if(idx ^ -1)
        return ERROR;
    List temp = mal_list ;
    temp->val = value;
    temp->next = p->next;
    p->next = temp;
    return OK;
}

// 反转链表
Status ReverseList(List& list){
    List a, b, c;
    if(!list->next || !list->next->next)
        return OK;
    a = NULL, b = list->next;
    while(b)
    {
        c = b->next;
        b->next = a;
        a = b; b = c;
    }
    list->next = a;
    return OK;
}
// 反转链表 递归写法
List ReverseListCreateNew(List head){
    if(!head || !head->next)
        return head; 
    List res = ReverseListCreateNew(head->next);
    head->next->next = head; 
    head->next = NULL;
    return res;
}

//用数组创建链表
List CreateList(int* arr, int len){
    List phead, p, s;
    phead = mal_list ;
    phead->next = NULL;
    p = phead;
    int i = 0; 
    for(; i < len; i ++)
    {
        s = mal_list ;
        s->next = NULL;
        s->val = *(arr + i);
        p->next = s;
        p = p->next;

    }
    return phead;
}

//打印链表
Status PrintList(List list){
    while(list->next)
    {
        list = list->next;
        printf("%d ", list->val);
    }
    puts("");
    return OK;
}




