#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <iostream>
const int N = 10010;
#define OK 1
#define ERROR 0
#define MAX_SIZE 100
#define mal (pointer)malloc(sizeof(struct node))
typedef char ElementType;

bool st[10010];

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

typedef struct SeqQueue{
    int q[MAX_SIZE];
    int hh, tt;
}queue;

void init(queue &q){
    q.hh = 0, q.tt = -1;
}

void push(queue& q, int val){
    q.q[ ++ q.tt] = val;
}
int front(queue& q){
    return q.q[q.hh];
}
void pop(queue& q){
    q.hh ++ ;
}
bool isempty(queue& q){
    return q.hh > q.tt;
}

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

void bfs(Graph g, int u){
    queue q;
    init(q);
    push(q, u);
    while(!isempty(q))
    {
        int t = front(q);
        pop(q);
        st[t] = true;
        printf("%c ", g.h[t].data);
        for(pointer p = g.h[t].first; p; p = p->next)
            if(!st[p->verx])
                push(q, p->verx);
    }
}

void solve(){
    Graph g;
    creat(g);
    memset(st, false, sizeof st);
    dfs(g, 0);
    puts("");
    memset(st, false, sizeof st);
    bfs(g, 0);

}

int main(){
    solve();
    return 0;
}