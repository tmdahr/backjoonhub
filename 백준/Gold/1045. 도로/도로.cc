#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int parent[55];

int my_par(int x) {
    while (x != parent[x]) {
        x = parent[x];
    }
    return x;
}

void union_set(int x, int y) {
    int par_x = my_par(x);

    // compress path while climbing y
    while (y != parent[y]) {
        int temp = y;
        y = parent[y];
        parent[temp] = par_x;
    }
    parent[y] = par_x;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char maps[55][55];
    for (int i = 0; i < n; i++) {
        scanf("%s", maps[i]);
    }

    // priority queue for (i, j)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> trash;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (maps[i][j] == 'Y') {
                pq.push({i, j});
            }
        }
    }

    if ((int)pq.size() < m) {
        printf("-1\n");
        return 0;
    }

    for (int i = 0; i < n; i++) parent[i] = i;

    int answer[55] = {0};
    int cnt = 0;

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int i = top.first;
        int j = top.second;

        if (my_par(i) != my_par(j)) {
            union_set(i, j);
            answer[i]++;
            answer[j]++;
            cnt++;
        } else {
            trash.push({i, j});
        }
    }

    if (cnt != n - 1) {
        printf("-1\n");
        return 0;
    }

    for (int k = 0; k < m - cnt; k++) {
        auto top = trash.top();
        trash.pop();
        int i = top.first;
        int j = top.second;
        answer[i]++;
        answer[j]++;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}
