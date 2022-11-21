#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <iostream>
#define OK 1
#define ERROR 0
#define MAX_SIZE 100
#define mal (pointer)malloc(sizeof(struct node))
typedef char ElementType;

bool st[MAX_SIZE];

typedef struct node{
    int verx;
    struct node* next;
}node, *pointer;

typedef struct{
    ElementType data;
    pointer first;
}head;
typedef struct Graph{
    head h[MAX_SIZE];
    int n, e;
}Graph;

void creat(Graph& g){
    int n, m, w, a, b;
    scanf("%d%d", &n, &m);
    g.n = n, g.e = m;
    for(int i = 0; i < n; i ++)
        scanf("\n%c", &g.h[i].data), g.h[i].first = NULL;
    for(int i = 0; i < m; i ++)
    {
        scanf("%d%d", &a, &b);
        pointer p = mal;
        p->verx = b;
        p->next = g.h[a].first;
        g.h[a].first = p;
    }
}

void dfs(Graph g, int u){
    ElementType x = g.h[u].data;
    st[u] = 1; 
    printf("%c ", x);
    for(pointer p = g.h[u].first; p; p = p->next)
        if(!st[p->verx])
            dfs(g, p->verx);
}

void solve(){
    Graph g;
    creat(g);
    memset(st, false, sizeof st);
    dfs(g, 0);
    puts("");
}

int main(){
    solve();
    return 0;
}