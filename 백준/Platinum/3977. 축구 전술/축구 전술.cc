#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

const int MAX = 100001;
vector<int> graph[MAX];
int id[MAX], scc_id[MAX], indegree[MAX];
bool finished[MAX];
int n, m, id_cnt, scc_cnt;
stack<int> st;

int dfs(int x) {
    id[x] = ++id_cnt;
    st.push(x);
    int parent = id[x];

    for(int next : graph[x]) {
        if(id[next] == 0)
            parent = min(parent, dfs(next));
        else if(!finished[next])
            parent = min(parent, id[next]);
    }

    if(parent == id[x]) {
        ++scc_cnt;
        while(1) {
            int top=st.top();
            st.pop();
            finished[top] = true;
            scc_id[top] = scc_cnt;
            if (top == x) break;
        }
    }

    return parent;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);

        // 초기화
        for(int i=0; i<n; i++) {
            graph[i].clear();
            id[i] = scc_id[i] = indegree[i] = 0;
            finished[i] = false;
        }
        id_cnt = scc_cnt = 0;

        // 간선 입력
        for(int i=0; i<m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
        }

        // SCC 구하기
        for(int i=0; i<n; i++)
            if(id[i] == 0)
                dfs(i);

        // SCC 간 간선 구성 후 indegree 계산
        for(int i=0; i<n; i++) {
            for(int next : graph[i]) {
                if(scc_id[i] != scc_id[next])
                    indegree[scc_id[next]]++;
            }
        }

        // indegree == 0인 SCC 찾기
        int zero_cnt=0, target=-1;
        for(int i=1; i<=scc_cnt; i++) {
            if(indegree[i] == 0) {
                zero_cnt++;
                target = i;
            }
        }

        if(zero_cnt != 1)
            printf("Confused\n");
        else {
            for(int i=0; i<n; i++)
                if(scc_id[i] == target)
                    printf("%d\n", i);
        }

        printf("\n");
    }

    return 0;
}
