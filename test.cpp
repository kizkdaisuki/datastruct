//PREPEND BEGIN
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;
List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */
List Reverse(List L);
//PREPEND END

//TEMPLATE BEGIN
List Reverse( List L){
    List res, temp;
    while(L)
    {
        temp = L->Next;
        L->Next = res;
        res = L;
        L = temp;
    }
    return res;
}
//TEMPLATE END

//APPEND BEGIN
int main() {
List L1, L2;
    L1 = Read();
    
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}
List Read()
{
    int n; scanf("%d", &n);
    List list=NULL, temp, p;
    if (n >= 1){
        list = (List)malloc(sizeof(Node));
        scanf("%d", &list->Data);
        list->Next = NULL; n--;
    }

    p = list;
    while (n--){
        temp = new Node();
        scanf("%d", &temp->Data);
        temp->Next = p->Next;
        p->Next = temp;
        p = p->Next;
        
    }

    
    return list;
}
void Print(List L)
{
    List temp = L;
    while (temp != NULL){
        cout << temp->Data << " ";
        temp = temp->Next;
    }
    putchar('\n');
}
//APPEND END