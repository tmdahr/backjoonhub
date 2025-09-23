#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int N, M;
vector<int> graph[10001], re_graph[10001];
bool visit[10001];
stack<int> s;
vector<vector<int>> scc;

bool cmp(vector<int>& a, vector<int>& b) {return a[0] < b[0];}

void dfs(int i) {
    visit[i] = true;
    for(int next : graph[i])
        if(!visit[next]) dfs(next);
    s.push(i);
}

void re_dfs(int i, vector<int>& component) {
    visit[i] = true;
    component.push_back(i);
    for(int next : re_graph[i]) {
        if(!visit[next]) re_dfs(next, component);
    }
}

int main(void) {
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        re_graph[b].push_back(a);
    }

    for(int i=1; i<=N; i++) if(!visit[i]) dfs(i);
    fill(visit, visit+N+1, false);

    while(!s.empty()) {
        int i = s.top();
        s.pop();
        if(!visit[i]) {
            vector<int> component;
            re_dfs(i, component);
            sort(component.begin(), component.end());
            scc.push_back(component);
        }
    }

    sort(scc.begin(), scc.end(), cmp);

    printf("%lu\n", scc.size());
    for(auto &comp : scc) {
        for(int x : comp) printf("%d ", x);
        printf("-1\n");
    }
}