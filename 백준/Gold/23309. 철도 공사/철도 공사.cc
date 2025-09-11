#include <cstdio>
#include <string>
using namespace std;

const int MAX = 1000000 + 5;
int prevStation[MAX], nextStation[MAX];

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    int first, last;
    scanf("%d", &first);
    int prev = first;

    for(int i=2; i<=N; i++)
    {
        int now;
        scanf("%d", &now);
        nextStation[prev] = now;
        prevStation[now] = prev;
        prev = now;
    }
    last = prev;
    nextStation[last] = first;
    prevStation[first] = last;

    char buf[3];
    for(int k=0; k<M; k++) {
        scanf("%s", buf);
        string cmd(buf);

        if(cmd == "BN")
        {
            int i, j;
            scanf("%d %d", &i, &j);
            printf("%d\n", nextStation[i]);
            int nxt = nextStation[i];
            nextStation[i] = j;
            prevStation[j] = i;
            nextStation[j] = nxt;
            prevStation[nxt] = j;
        }
        else if(cmd == "BP")
        {
            int i, j;
            scanf("%d %d", &i, &j);
            printf("%d\n", prevStation[i]);
            int prv = prevStation[i];
            prevStation[i] = j;
            nextStation[j] = i;
            prevStation[j] = prv;
            nextStation[prv] = j;
        }
        else if(cmd == "CN")
        {
            int i;
            scanf("%d", &i);
            int nxt = nextStation[i];
            printf("%d\n", nxt);
            int nxt2 = nextStation[nxt];
            nextStation[i] = nxt2;
            prevStation[nxt2] = i;
        }
        else if(cmd == "CP")
        {
            int i;
            scanf("%d", &i);
            int prv = prevStation[i];
            printf("%d\n", prv);
            int prv2 = prevStation[prv];
            prevStation[i] = prv2;
            nextStation[prv2] = i;
        }
    }
    return 0;
}