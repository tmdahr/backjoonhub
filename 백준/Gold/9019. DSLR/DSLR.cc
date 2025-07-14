#include <stdio.h>
#include <string.h>
#define MAX 10002

int from[MAX];
char how[MAX];
int queue[MAX];
int visit[MAX];

int D(int n) {return n*2%10000;}
int S(int n) {return n==0 ? 9999 : n-1;}
int L(int n) { return n%1000*10 + n/1000;}
int R(int n) { return n%10*1000 + n/10;}

void print(int a, int b)
{
    if(a==b) return ;
    print(a,from[b]);
    printf("%c", how[b]);
}

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        memset(visit, 0, sizeof(visit));
        memset(from,-1,sizeof(from));
        int a, b, front=0, rear=0;
        scanf("%d %d", &a, &b);
        queue[rear++] = a;
        visit[a] = 1;
        from[a] = -1;
        
        while(front < rear)
        {
            int now = queue[front++];
            int next;
            
            next=D(now);
            if(!visit[next])
            {
                visit[next]=1;
                from[next] = now;
                how[next] = 'D';
                queue[rear++] = next;
                if(next==b) break;
            }
            next=S(now);
            if(!visit[next])
            {
                visit[next]=1;
                from[next] = now;
                how[next] = 'S';
                queue[rear++] = next;
                if(next==b) break;
            }
            next=L(now);
            if(!visit[next])
            {
                visit[next]=1;
                from[next] = now;
                how[next] = 'L';
                queue[rear++] = next;
                if(next==b) break;
            }
            next=R(now);
            if(!visit[next])
            {
                visit[next]=1;
                from[next] = now;
                how[next] = 'R';
                queue[rear++] = next;
                if(next==b) break;
            }
        }
        print(a, b);
        printf("\n");
    }
    
    return 0;
}