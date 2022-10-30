//
//  main.c
//  zsy2_2
//
//  Created by 赵诗意 on 2022/9/26.
//

#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

LinkList CreateList_L(LinkList head)
{ElemType temp;
    LinkList p;
    printf("请输人结点值(输人0结束):\n");
    scanf("%d", &temp);
    while(temp) {
            printf("请输人结点值(输人0结束):\n");
            p= (LinkList)malloc(sizeof(LNode));
            p-> data = temp;
            p-> next = head->next;
            head -> next = p;
            scanf("%d", &temp);
        }
        return head;
    }

void ListPint_L(LinkList head)
{LinkList p;
    int i = 0;
    p= head->next;
    while(p)
    {
        i ++ ;
        printf("第%d个元素是：%d \n", i, p->data);
        p = p->next;
    }
}

void merge(LinkList L1, LinkList L2, LinkList L3){
    LinkList p = L3;
    while(L1 && L2)
    {
        if(L1->data <= L2->data)
            p->next = L1, L1 = L1->next;
        else
            p->next = L2, L2 = L2->next;
        p = p->next;
    }
    while(L1)
        p->next = L1, L1 = L1->next, p = p->next;
    while(L2)
        p->next = L2, L2 = L2->next, p = p->next;
    p->next = NULL;
}

int main(){
    LinkList L1 = (LinkList)malloc(sizeof (LNode));
    LinkList L2 = (LinkList)malloc(sizeof (LNode));
    LinkList L3 = (LinkList)malloc(sizeof (LNode));
    L1->next = NULL;
    L2->next = NULL;
    L3->next = NULL;
    printf("请输入L1的结点:\n");
    CreateList_L(L1);
    printf("请输入L2的结点:\n");
    CreateList_L(L2);
    printf("链表L1：\n");
    ListPint_L(L1);
    printf("链表L2：\n");
    ListPint_L(L2);
    merge(L1->next,L2->next,L3);
    printf("L1和L2合并:\n");
    ListPint_L(L3);
    return 0;
}