#include <stdio.h>

int parent[1005];

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
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			int num;
			scanf("%d", &num);
			if(num==1)
			{
				merge(i,j);
			}
		}
	}
	
	int p,c,pp,pc;
	scanf("%d", &p);
	for(int i=1; i<m; i++)
	{
		scanf("%d", &c);
		pp = parent[p];
		pc = parent[c];
		
		if(pp!=pc)
		{
			puts("NO");
			break;
		}
		else if(i==m-1) puts("YES");
		pp = pc;
	}
	
	return 0;
}