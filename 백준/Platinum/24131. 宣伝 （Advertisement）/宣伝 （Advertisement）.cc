#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

#define MAX 200000

int N, M;
vector<int> adj[MAX+1];

int dfsn[MAX+1];
int low[MAX+1];
bool finished[MAX+1];
int sccId[MAX+1];

int dfscnt = 0;
int sccCnt = 0;
stack<int> st;

int indegree[MAX+1];

int dfs(int u) {
    dfsn[u] = low[u] = ++dfscnt;
    st.push(u);

    for(int v : adj[u]) {
        if(dfsn[v] == 0)
            low[u] = min(low[u], dfs(v));
        else if(!finished[v])
            low[u] = min(low[u], dfsn[v]);
    }

    if(low[u] == dfsn[u]) {
        sccCnt++;
        while(true) {
            int t = st.top();
            st.pop();
            finished[t] = true;
            sccId[t] = sccCnt;
            if(t == u) break;
        }
    }
    return low[u];
}

int main(void) {
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
    }

    for(int i=1; i<=N; i++)
        if(dfsn[i] == 0) dfs(i);

    for(int u=1; u<=N; u++)
        for(int v : adj[u])
            if(sccId[u] != sccId[v])
                indegree[sccId[v]]++;

    int answer = 0;
    for(int i=1; i<=sccCnt; i++)
        if(indegree[i] == 0) answer++;

    printf("%d\n", answer);
    return 0;
}
