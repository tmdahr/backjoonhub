#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

typedef struct _node
{
	int r,c;
} node;
int n, m, ans = 2147483647;
int map[55][55];
vector<node> h, c;
vector<int> arr;

int find(void)
{
	int sum=0;
	for(int i=0; i<h.size(); i++)
	{
		int dm=2147483647;
		for(int j=0; j<arr.size(); j++)
		{
			int d = abs(h[i].r-c[arr[j]].r)+abs(h[i].c-c[arr[j]].c);
			dm=min(dm,d);
		}
		sum+=dm;
	}
	return sum;
}

void back(int num, int s)
{
	if(s==m) ans = min(ans, find());
	else
	{
		for(int i=num; i<c.size(); i++)
		{
			arr.push_back(i);
			back(i+1,s+1);
			arr.pop_back();
		}
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j]==1) h.push_back({i,j});
			else if(map[i][j]==2) c.push_back({i,j});
		}
	back(0,0);
	printf("%d", ans);
	
	return 0;
}