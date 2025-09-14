#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

int main() {
    long long n;
    int k, w;
    scanf("%lld %d", &n, &k);

    vector<int> S(k);      // 가져갈 수 있는 돌의 수
    int maxS = 0;
    for(int i = 0; i < k; i++) {
        scanf("%d", &S[i]);
        if(S[i] > maxS) maxS = S[i];
    }

    deque<int> brr;  // 전체 DP 상태 (상근 승 = 1, 창영 승 = 2)
    deque<int> crr;  // 반복 패턴 탐지용

    brr.push_back(2); // 0번째는 창영 승

    long long total_win = 0;

    if(n > 1000) {
        long long counta = 0;

        // 1~1000까지 DP 계산
        for(int i = 1; i <= 1000; i++) {
            bool canWin = false;
            for(int j = 0; j < k; j++) {
                if(S[j] > i) break;
                if(brr[i - S[j]] == 2) { // 상대가 지면 승
                    canWin = true;
                    break;
                }
            }
            if(canWin) brr.push_back(1);
            else { brr.push_back(2); counta++; }
        }

        // 1001~4001까지 DP + 반복 패턴 탐지용 crr 저장
        for(int i = 1001; i <= 4001; i++) {
            bool canWin = false;
            for(int j = 0; j < k; j++) {
                if(S[j] > i) break;
                if(brr[i - S[j]] == 2) {
                    canWin = true;
                    break;
                }
            }
            if(canWin) { brr.push_back(1); crr.push_back(1); }
            else { brr.push_back(2); crr.push_back(2); }
        }

        // 반복 주기 탐지
        int roop = 0, roopsize = 0;
        while(!crr.empty()) {
            if(crr.size() % 2 == 1) {
                crr.pop_back();
                continue;
            }

            bool roopout = true;
            int half = crr.size() / 2;
            for(int i = 0; i < half; i++) {
                if(crr[i] != crr[i + half]) {
                    roopout = false;
                    break;
                }
            }

            if(roopout) {
                roop = half;
                for(int i = 0; i < half; i++) if(crr[i] == 2) roopsize++;
                break;
            }
            else crr.pop_back();
        }

        n -= 1000;
        total_win = counta + (roopsize * (n / roop));
        n %= roop;

        // 나머지 남은 n 처리
        while(crr.size() < maxS) {
            int size = crr.size();
            for(int i = 0; i < size; i++) crr.push_back(crr[i]);
        }
        while(crr.size() > maxS) crr.pop_front();

        for(int i = 0; i < n; i++) {
            bool canWin = false;
            for(int j = 0; j < k; j++) {
                if(crr[maxS - S[j]] == 2) { // 상대가 지면 승
                    canWin = true;
                    break;
                }
            }
            if(canWin) crr.push_back(1);
            else { crr.push_back(2); total_win++; }
            crr.pop_front();
        }

        printf("%lld\n", total_win);
    }
    else {
        // n <= 1000 일 때 단순 DP
        long long count = 0;
        for(int i = 1; i <= n; i++) {
            bool canWin = false;
            for(int j = 0; j < k; j++) {
                if(S[j] > i) break;
                if(brr[i - S[j]] == 2) { canWin = true; break; }
            }
            if(canWin) brr.push_back(1);
            else { brr.push_back(2); count++; }
        }
        printf("%lld\n", count);
    }

    return 0;
}
