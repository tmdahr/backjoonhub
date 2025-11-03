#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAXC = 100000;

int c, b;
vector<int> graph[MAXC+1];

int id[MAXC+1];
bool finished[MAXC+1];
int scc_id[MAXC+1];
int idx = 1;
vector<vector<int>> sccs;
stack<int> st;

// Tarjan SCC
int dfs(int x) {
    id[x] = idx++;
    int parent = id[x];
    st.push(x);

    for(int nxt : graph[x]) {
        if(id[nxt] == 0)
            parent = min(parent, dfs(nxt));
        else if(!finished[nxt])
            parent = min(parent, id[nxt]);
    }

    if(parent == id[x]) {
        vector<int> scc;
        while(true) {
            int t = st.top(); st.pop();
            finished[t] = true;
            scc_id[t] = (int)sccs.size();
            scc.push_back(t);
            if(t == x) break;
        }
        sccs.push_back(scc);
    }
    return parent;
}

int main(void) {
    scanf("%d %d", &c, &b);

    for(int i=0; i<b; i++) {
        int li, mi;
        scanf("%d %d", &li, &mi);
        for(int j=0; j<mi; j++) {
            int a;
            scanf("%d", &a);
            graph[li].push_back(a);
        }
    }

    for(int i=1; i<=c; i++) {
        if(id[i] == 0) dfs(i);
    }

    int scc_count = sccs.size();
    vector<int> indeg(scc_count, 0);

    // SCC 그래프의 진입 간선 계산
    for(int u=1; u<=c; u++) {
        for(int v : graph[u]) {
            if(scc_id[u] != scc_id[v])
                indeg[scc_id[v]]++;
        }
    }

    // 진입 간선이 없는 SCC를 찾는다
    int zero_in_scc = -1;
    int zero_in_cnt = 0;
    for(int i=0; i<scc_count; i++) {
        if(indeg[i] == 0) {
            zero_in_cnt++;
            zero_in_scc = i;
        }
    }

    // 진입 간선이 없는 SCC가 1개면, 그 안의 노드 개수 출력
    if(zero_in_cnt == 1)
        printf("%d\n", (int)sccs[zero_in_scc].size());
    else
        printf("0\n");

    return 0;
}
