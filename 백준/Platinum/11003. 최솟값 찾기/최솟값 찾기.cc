#include <cstdio>
#include <deque>
using namespace std;

#define MAX 5000010

int N, L;
int Arr[MAX];

int main()
{
    scanf("%d %d", &N, &L);
    for(int i=1; i<=N; i++) scanf("%d", &Arr[i]);
    
    deque<pair<int, int>> dq;
    for(int i=1; i<=N; i++) {
        if(!dq.empty() && dq.front().second < i-L+1)
            dq.pop_front();

        while(!dq.empty() && dq.back().first > Arr[i])
            dq.pop_back();

        dq.push_back({Arr[i], i});
        printf("%d ", dq.front().first);
    }
    printf("\n");
    
    return 0;
}