#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

static const int MAX = 1000;

vector<int> g[MAX+1];
int cost[MAX+1];
int id[MAX+1], low[MAX+1], scc_id[MAX+1];
bool on_stack[MAX+1];
stack<int> st;
int idx, scc_count;

void dfs(int u) {
    id[u] = low[u] = ++idx;
    st.push(u);
    on_stack[u] = true;

    for(int v : g[u]) {
        if(id[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(on_stack[v]) {
            low[u] = min(low[u], id[v]);
        }
    }

    if(low[u] == id[u]) {
        scc_count++;
        while(true) {
            int v = st.top();
            st.pop();
            on_stack[v] = false;
            scc_id[v] = scc_count;
            if(v == u) break;
        }
    }
}

int main(void) {
    int N;
    scanf("%d", &N);

    for(int i=1; i<=N; i++)
        scanf("%d", &cost[i]);

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            char c;
            scanf(" %c", &c);
            if(c == '1')
                g[i].push_back(j);
        }
    }

    for(int i=1; i<=N; i++)
        if(id[i] == 0) dfs(i);

    int scc_min[MAX+1];
    for(int i=1; i <= scc_count; i++)
        scc_min[i] = 1e9;
    for(int i=1; i<=N; i++)
        scc_min[scc_id[i]] = min(scc_min[scc_id[i]], cost[i]);

    int ans = 0;
    for(int i=1; i<=scc_count; i++)
        ans += scc_min[i];

    printf("%d\n", ans);
    return 0;
}
