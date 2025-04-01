#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _node{
	int from,to,cost;
}node;

bool cmp(node a,node b)
{
	return a.cost<b.cost;
}

int parent[10005];

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
	else if(n<v) parent[v]=n;
	else parent[n]=v;
}

int main()
{
	vector<node> map;
	int V,E, res=0;
	scanf("%d%d",&V,&E);
	
	for(int i=1; i<=V; i++) parent[i]=i;
	
	for(int i=0;i<E;i++)
	{
		int from,to,cost;
		scanf("%d%d%d",&from,&to,&cost);
		map.push_back({from,to,cost});
	}
	sort(map.begin(),map.end(),cmp);
	for(int i=0;i<E;i++)
	{
		int a=find(map[i].from);
		int b=find(map[i].to);
		if(a==b)
			continue;
		
		merge(map[i].from,map[i].to);
		res+=map[i].cost;
	}
	
	printf("%d", res);
	
	return 0;
}