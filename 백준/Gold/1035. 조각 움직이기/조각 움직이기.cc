#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

char board[5][6];
bool visited[5][5];
vector<pair<int,int>> pieces;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

// BFS로 연결 여부 확인
bool isConnected(const vector<pair<int,int>>& tgt) {
    int cnt = tgt.size();
    if(cnt <= 1) return true;

    // 방문 초기화
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            visited[i][j] = false;

    queue<pair<int,int>> q;
    q.push(tgt[0]);
    visited[tgt[0].first][tgt[0].second] = true;
    int connected = 1;

    while(!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        for(int d=0; d<4 ;d++) {
            int nx = x+dx[d], ny = y+dy[d];
            for(auto &p : tgt) {
                if(p.first==nx && p.second==ny && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                    connected++;
                }
            }
        }
    }
    return connected == cnt;
}

// 맨해튼 거리 합 계산
int calcDist(const vector<pair<int,int>>& a, const vector<pair<int,int>>& b) {
    int n = a.size();
    int dist = 0;
    for(int i=0; i<n; i++) dist += abs(a[i].first - b[i].first) + abs(a[i].second - b[i].second);
    return dist;
}

int main(void) {
    for(int i=0; i<5; i++) {
        scanf("%s", board[i]);
        for(int j=0; j<5; j++) 
            if(board[i][j] == '*')
                pieces.push_back({i,j});
    }

    int K = pieces.size();
    vector<pair<int,int>> cells;

    // 전체 25칸 중 K개를 선택 → 조합 생성
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            cells.push_back({i,j});

    int answer = 1e9;

    vector<int> mask(25,0);
    for(int i=0; i<K; i++) mask[i] = 1;

    // next_permutation 으로 모든 K칸 선택
    sort(mask.begin(), mask.end(), greater<int>());
    do {
        vector<pair<int,int>> tgt;
        for(int i=0; i<25; i++)
            if(mask[i])
                tgt.push_back(cells[i]);

        // 선택된 칸들이 연결되어야 함
        if(!isConnected(tgt)) continue;

        // 원래 조각 위치와 매칭 → 최소 이동 거리 계산
        vector<int> ord(K);
        for(int i=0; i<K; i++) ord[i] = i;

        do {
            vector<pair<int,int>> reordered(K);
            for(int i=0;i<K;i++) reordered[i] = tgt[ord[i]];

            int cost = calcDist(pieces, reordered);
            answer = min(answer, cost);
        }
        while(next_permutation(ord.begin(), ord.end()));
    }
    while(prev_permutation(mask.begin(), mask.end()));

    printf("%d\n", answer);
    return 0;
}
