#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

vector<int> t[50];
queue<int> q;

int solution(int x)
{
	int c=0;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		if(t[now].size()==0) c++;
		else
		{
			for(int i=0; i<t[now].size(); i++)
			{
				if(t[now][i]!=x) q.push(t[now][i]);
				else if(t[now].size()-1==0) c++;
			}
		}
	}
	
	return c;
}

int main(void)
{
	int n, x, c=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int p;
		scanf("%d", &p);
		if(p==-1) q.push(i);
		else t[p].push_back(i);
	}
	scanf("%d", &x);
	if(x!=q.front()) c = solution(x);
	printf("%d", c);
	
	return 0;
}