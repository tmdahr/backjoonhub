#include <stdio.h>

int parent[55], people[55][55];

int find(int v)
{
	if(parent[v]==v) return v;
	else return parent[v]=find(parent[v]);
}

void merge(int n, int v)
{
	n = find(n);
	v = find(v);
	
	if(n==v) return;
	if(n<v) parent[v] = n;
	else parent[n] = v;
}

int main(void)
{
	int n, m, p, tp, i, t=0;
	
	scanf("%d %d", &n, &m);
	for(i=0; i<=n; i++)
	{
		parent[i]=i;
	}
	
	scanf("%d", &tp);
	if(tp!=0) scanf("%d", &t);
	for(i=0; i<tp-1; i++)
	{
		scanf("%d", &p);
		merge(t, p);
	}
	
	for(i=0; i<m; i++)
	{
		scanf("%d", &p);
		for(int j=0; j<p; j++)
		{
			scanf("%d", &people[i][j]);
			if(j!=0) merge(people[i][j],people[i][j-1]);
		}
	}
	
	t = find(t);
	p=0;
	for(i=0; i<m; i++)
	{
		if(find(people[i][0])!=t) p++;
	}
	printf("%d", p);
	
	return 0;
}