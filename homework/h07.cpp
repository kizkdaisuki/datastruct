#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <iostream>

#define OK 1
#define ERROR 0
#define MAX_SIZE 100

typedef int ElementType;

bool st[MAX_SIZE];

typedef struct Graph{
    ElementType vexs[MAX_SIZE];
    ElementType g[MAX_SIZE][MAX_SIZE];
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
    memset(g.g, -1, sizeof g.g);
    scanf("%d%d", &n, &m);
    g.n = n, g.e = m;
    for(int i = 0; i < n; i ++)
        scanf("%d", &g.vexs[i]);
    for(int i = 0; i < m; i ++)
    {
        scanf("%d%d%d", &a, &b, &w);
        g.g[a][b] = w; 
    }
}

void dfs(Graph g, int u){
    st[u] = 1; 
    printf("%d ", u);
    for(int i = 0; i < g.n; i ++)
        if(g.g[u][g.vexs[i]] != -1 && !st[g.vexs[i]])
            dfs(g, g.vexs[i]);
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
        printf("%d ", t);
        for(int i = 0; i < g.n; i ++)
            if(g.g[t][g.vexs[i]] != -1 && !st[g.vexs[i]])
                push(q, g.vexs[i]);

    }
}

void solve(){
    Graph g;
    creat(g);
    dfs(g, g.vexs[0]);
    puts("");
    memset(st, false, sizeof st);
    bfs(g, g.vexs[0]);
    puts("");
}

int main(){
    solve();
    return 0;
}