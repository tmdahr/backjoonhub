#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
#define MAX 200005

int N, M;
vector<int> g[MAX], rg[MAX];
int visit[MAX];
stack<int> st;

void dfs(int u) {
    visit[u] = 1;
    for(int v : g[u]) if(!visit[v]) dfs(v);
    st.push(u);
}

void rdfs(int u) {
    visit[u] = 1;
    for(int v : rg[u]) if(!visit[v]) rdfs(v);
}

int main(void) {
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    for(int i=1; i<=N; i++) if(!visit[i]) dfs(i);
    for(int i=1; i<=N; i++) visit[i]=0;
    int scc=0;
    while(!st.empty()) {
        int u=st.top();
        st.pop();
        if(!visit[u]) {
            rdfs(u);
            scc++;
        }
    }

    printf("%s\n", scc==1?"Yes":"No");
    return 0;
}