#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int N, M;
int degree[MAX+1];
int graph[MAX+1][MAX];
int size[MAX+1];
int result[MAX];
int front=0, rear=0;
int queue[MAX];

void enqueue(int x){queue[rear++] = x;}
int dequeue(){return queue[front++];}

int main(void)
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++)
    {
        int k, prev, cur;
        scanf("%d", &k);
        if(k==0) continue;
        scanf("%d", &prev);
        for(int j=1;j<k;j++)
        {
            scanf("%d", &cur);
            graph[prev][size[prev]++] = cur;
            degree[cur]++;
            prev = cur;
        }
    }
    for(int i=1; i<=N; i++)
    {
        if(degree[i]==0) enqueue(i);
    }
    int idx=0;
    while(front < rear)
    {
        int p = dequeue();
        result[idx++] = p;
        for(int j=0; j<size[p]; j++)
        {
            int v = graph[p][j];
            if(--degree[v]==0) enqueue(v);
        }
    }
    if(idx != N) printf("0\n");
    else
    {
        for(int i=0; i<N; i++) printf("%d\n", result[i]);
    }
    return 0;
}