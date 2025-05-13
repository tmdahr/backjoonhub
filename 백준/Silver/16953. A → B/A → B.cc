#include <stdio.h>
#include <queue>
using namespace std;

int a, b;
struct node {
    long long  num;
    int count;
    node(int n, int c) : num(n), count(c) {}  // 생성자 추가
};

int BFS(int num)
{
    queue<node> q;
    q.push(node(num, 1));

    while(!q.empty())
    {
        node now = q.front();
        q.pop();
        if(now.num*2==b) return now.count+1;
        if(now.num*2<b) q.push(node(now.num*2, now.count+1));
        if(now.num*10+1==b) return now.count+1;
        if(now.num*10+1<b) q.push(node(now.num*10+1, now.count+1));
    }
    return -1;
}

int main(void)
{
    scanf("%d %d", &a, &b);
    printf("%d\n", BFS(a));

    return 0;
}