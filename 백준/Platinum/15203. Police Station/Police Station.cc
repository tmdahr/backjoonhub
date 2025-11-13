#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX = 1000005;

int N, M;
vector<int> adj[MAX];
int id[MAX], sccId[MAX], indeg[MAX];
bool finished[MAX];
int id_cnt = 0, scc_cnt = 0;
stack<int> st;
vector<int> scc_nodes[MAX];

int DFS(int x) {
    id[x] = ++id_cnt;
    st.push(x);

    int parent = id[x];
    for(int nxt : adj[x]) {
        if(id[nxt] == 0) parent = min(parent, DFS(nxt));
        else if(!finished[nxt]) parent = min(parent, id[nxt]);
    }

    if(parent == id[x]) {
        scc_cnt++;
        while(1) {
            int t = st.top(); st.pop();
            finished[t] = true;
            sccId[t] = scc_cnt;
            scc_nodes[scc_cnt].push_back(t);
            if(t == x) break;
        }
    }
    return parent;
}

int main(void) {
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
    }

    for(int i=1; i<=N; i++)
        if(id[i] == 0) DFS(i);

    for(int i=1; i<=N; i++)
        for(int nxt : adj[i])
            if(sccId[i] != sccId[nxt])
                indeg[sccId[nxt]]++;

    vector<int> zero_scc;
    for(int i=1; i<=scc_cnt; i++)
        if(indeg[i] == 0) zero_scc.push_back(i);

    if(zero_scc.size() != 1) {
        printf("0\n");
        return 0;
    }

    vector<int> result = scc_nodes[zero_scc[0]];
    sort(result.begin(), result.end());

    printf("%d\n", (int)result.size());
    for(int i=0; i<(int)result.size(); i++)
        printf("%d ", result[i]);
    printf("\n");
    return 0;
}
