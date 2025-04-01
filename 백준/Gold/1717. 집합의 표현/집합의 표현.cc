#include <stdio.h>

int parent[1000005];

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
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<=n; i++)
	{
		parent[i]=i;
	}
	
	for(int i=0; i<m; i++)
	{
		int num, a,b;
		scanf("%d %d %d", &num, &a, &b);
		
		if(num==0) merge(a,b);
		else
		{
			int pa,pb;
			pa = find(a);
			pb = find(b);
			
			if(pa==pb) puts("YES");
			else puts("NO");
		}
	}
	
	return 0;
}