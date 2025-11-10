#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
    long long x, y;
};

int N;
vector<Point> points;
double ans;

void dfs(int idx, int cnt, long long sx, long long sy) {
    if(cnt > N/2) return; // + 선택이 N/2를 넘으면 불가능
    if(idx == N) {
        if(cnt == N/2) { // 정확히 N/2개 + 선택
            double len = sqrt((double)sx*sx + (double)sy*sy);
            if(len < ans) ans = len;
        }
        return;
    }
    // idx번째 점 + 방향
    dfs(idx+1, cnt+1, sx+points[idx].x, sy+points[idx].y);
    // idx번째 점 - 방향
    dfs(idx+1, cnt, sx-points[idx].x, sy-points[idx].y);
}

int main(void) {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        points.resize(N);
        long long sumX = 0, sumY = 0;
        for(int i=0; i<N; i++) {
            scanf("%lld %lld", &points[i].x, &points[i].y);
            sumX += points[i].x;
            sumY += points[i].y;
        }
        ans = 1e18;
        dfs(0, 0, 0, 0);
        printf("%.12lf\n", ans);
    }
    return 0;
}