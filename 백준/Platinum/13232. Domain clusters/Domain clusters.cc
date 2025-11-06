#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

static const int MAX = 5000;

vector<int> g[MAX+1];
int id[MAX+1], low[MAX+1], scc_id[MAX+1];
bool on_stack[MAX+1];
int idx, scc_count;
stack<int> st;

int dfs(int u) {
    id[u] = low[u] = ++idx;
    st.push(u);
    on_stack[u] = true;

    for(int v : g[u]) {
        if(id[v] == 0) {
            dfs(v);
            low[u] = (low[u] < low[v] ? low[u] : low[v]);
        }
        else if(on_stack[v]) {
            low[u] = (low[u] < id[v] ? low[u] : id[v]);
        }
    }

    // 발견된 SCC
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
    return 0;
}

int main() {
    int D, L;
    scanf("%d", &D);
    scanf("%d", &L);

    for(int i=1; i<=D; i++) {
        g[i].clear();
        id[i] = low[i] = scc_id[i] = 0;
        on_stack[i] = false;
    }
    idx = scc_count = 0;

    for(int i=0; i<L; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
    }

    for(int i=1; i<=D; i++)
        if(id[i] == 0) dfs(i);

    // SCC 크기 측정
    int cnt[MAX+1] = {0};
    for(int i=1; i<=D; i++)
        cnt[scc_id[i]]++;

    int ans = 0;
    for(int i=1; i<=scc_count; i++)
        if(cnt[i] > ans) ans = cnt[i];

    printf("%d\n", ans);
    return 0;
}
