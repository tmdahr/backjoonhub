#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

vector<int> graph[100001];
vector<int> re_graph[100001];
bool visit[100001];
int scc[100001];
int N, M;
int scc_count;

void dfs(int u, stack<int>& st) {
    visit[u] = true;
    for(int v : graph[u])
        if(!visit[v]) dfs(v, st);
    st.push(u);
}

void re_dfs(int u, int id) {
    visit[u] = true;
    scc[u] = id;
    for(int v : re_graph[u])
        if(!visit[v]) re_dfs(v, id);
}

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        scanf("%d %d", &N, &M);

        for(int i=1; i<=N; i++) {
            graph[i].clear();
            re_graph[i].clear();
            visit[i] = false;
            scc[i] = 0;
        }
        scc_count = 0;

        for(int i=0; i<M; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            re_graph[v].push_back(u);
        }

        stack<int> st;
        for(int i=1; i<=N; i++)
            if(!visit[i]) dfs(i, st);

        for(int i=1; i<=N; i++) visit[i] = false;
        while(!st.empty()) {
            int u = st.top();
            st.pop();
            if(!visit[u]) {
                scc_count++;
                re_dfs(u, scc_count);
            }
        }

        vector<int> indegree(scc_count + 1, 0);
        for(int u=1; u<=N; u++)
            for(int v : graph[u])
                if(scc[u] != scc[v]) indegree[scc[v]]++;

        int count = 0;
        for(int i=1; i<=scc_count; i++)
            if(indegree[i] == 0) count++;

        printf("%d\n", count);
    }

    return 0;
}