#include <stdio.h>
#define MOD 1000000

int num[100001], pos[100001];
int n, x, ans;

void cal(int n) {
    num[0] = 1;
    for (int i = 1; i <= n; i++)
        num[i] = (num[i - 1] * 2) % MOD;
}

void hanoi(int disc, int to) {
    if (disc == 0) return;

    int now = pos[disc];
    int sub = 6 - now - to;  // 보조 기둥 계산 (1+2+3=6)

    if (now == to) {
        hanoi(disc - 1, to);
    } else {
        ans = (ans + num[disc - 1]) % MOD;
        hanoi(disc - 1, sub);
    }
}

int main() {
    scanf("%d", &n);
    cal(n);

    int pole1, pole2, pole3;
    scanf("%d %d %d", &pole1, &pole2, &pole3);

    // 1번 기둥 디스크 입력
    for (int i = 0; i < pole1; i++) {
        scanf("%d", &x);
        pos[x] = 1;
    }
    // 2번 기둥 디스크 입력
    for (int i = 0; i < pole2; i++) {
        scanf("%d", &x);
        pos[x] = 2;
    }
    // 3번 기둥 디스크 입력
    for (int i = 0; i < pole3; i++) {
        scanf("%d", &x);
        pos[x] = 3;
    }

    hanoi(n, pos[n]);
    printf("%d\n%d\n", pos[n], ans);

    return 0;
}