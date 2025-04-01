#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct _node
{
	int from, to, cost;
} node;
int parent[1000];

int find(int v)
{
	if(parent[v]==v) return v;
	else return parent[v] = find(parent[v]);
}

void merge(int n, int v)
{
	n = find(n);
	v = find(v);
	if(n==v) return;
	
	 if(n<v) parent[v]=n;
	else parent[n]=v;
}

bool cmp(node a, node b)
{
	return a.cost<b.cost;
}

int main(void)
{
	vector<node> map;
	int n, m, i, from, to, cost, res=0;
	
	scanf("%d %d", &n, &m);
	for(i=0; i<=n; i++) parent[i]=i;
	for(i=0; i<m; i++)
	{
		scanf("%d %d %d", &from, &to, &cost);
		map.push_back({from, to, cost});
	}
	sort(map.begin(),map.end(),cmp);
	for(i=0; i<m; i++)
	{
		int a = find(map[i].from);
		int b = find(map[i].to);
		if(a==b) continue;
		merge(map[i].from, map[i].to);
		res+=map[i].cost;
	}
	printf("%d", res);
	
	return 0;
}