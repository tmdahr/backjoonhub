#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int L;
    scanf("%d", &L);

    int S[1001];
    for(int i=0; i<L; i++) scanf("%d", &S[i]);

    int n;
    scanf("%d", &n);

    for(int i=0; i<L; i++) {
        if(S[i] == n) {
            printf("0\n");
            return 0;
        }
    }

    sort(S, S+L);

    int Lbound = 0;
    int Rbound = 1001;

    for(int i=0; i<L; i++) {
        if(S[i] < n) Lbound = S[i];
        if(S[i] > n) {
            Rbound = S[i];
            break;
        }
    }

    int left_cnt = n - Lbound;
    int right_cnt = Rbound - n;

    int ans = left_cnt * right_cnt - 1;
    printf("%d\n", ans);
    return 0;
}