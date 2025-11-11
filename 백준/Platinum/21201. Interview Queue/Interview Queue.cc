#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N;
    scanf("%d", &N);

    vector<long long> v(N);
    for(int i=0; i<N; i++) scanf("%lld", &v[i]);

    vector<int> prev(N), next(N), alive(N, 1);
    for(int i=0; i<N; i++) {
        prev[i] = i-1;
        next[i] = i+1;
    }
    next[N-1] = -1;

    vector<int> cur, nxt, mark(N, 0);
    cur.reserve(N);
    nxt.reserve(N);

    // 처음 라운드 검사 대상: 전체
    for(int i=0; i<N; i++) cur.push_back(i);

    vector<vector<long long>> rounds;
    vector<int> deaths;
    deaths.reserve(N);

    while(!cur.empty()) {
        deaths.clear();

        // 이번 라운드에서 죽는 후보 판정
        for(int x : cur) {
            if(!alive[x]) continue;
            int p = prev[x], n = next[x];
            if((p != -1 && alive[p] && v[p] > v[x]) || (n != -1 && alive[n] && v[n] > v[x])) {
                deaths.push_back(x);
            }
        }

        if(deaths.empty()) break;

        // 출력용 정렬 (기존 위치 기준)
        sort(deaths.begin(), deaths.end());
        rounds.push_back({});
        for(int x : deaths) rounds.back().push_back(v[x]);

        // 삭제 및 링크 정리
        for(int x : deaths) {
            alive[x] = 0;
            int p = prev[x], n = next[x];
            if(p != -1) next[p] = n;
            if(n != -1) prev[n] = p;
        }

        // 다음 라운드 검사 후보 수집 (죽은 사람의 양 옆만)
        nxt.clear();
        for(int x : deaths) {
            int p = prev[x], n = next[x];
            if(p != -1 && alive[p] && !mark[p]) {
                mark[p] = 1, nxt.push_back(p);
            }
            if(n != -1 && alive[n] && !mark[n]) {
                mark[n] = 1, nxt.push_back(n);
            }
        }

        // mark 초기화
        for(int x : nxt) mark[x] = 0;
        cur = nxt;
    }

    // 출력
    printf("%d\n", (int)rounds.size());
    for(auto &line : rounds) {
        for(size_t i=0; i<line.size(); i++) {
            if(i) printf(" ");
            printf("%lld", line[i]);
        }
        printf("\n");
    }

    // 살아남은 애들 출력
    int first = 1;
    for(int i=0; i<N; i++) {
        if(alive[i]) {
            if(!first) printf(" ");
            first = 0;
            printf("%lld", v[i]);
        }
    }
    printf("\n");

    return 0;
}