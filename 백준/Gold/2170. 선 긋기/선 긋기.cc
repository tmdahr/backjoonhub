#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

typedef struct _node
{
	int s, e;
} node;
struct cmp
{
	bool operator()(node a, node b)
	{
		return a.s>b.s;
	}
};
priority_queue<node, vector<node>, cmp> pq;

int main(void)
{
	int n, len=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int x,y;
		scanf("%d %d", &x, &y);
		pq.push({x,y});
	}
	
	int start = pq.top().s;
	int end = pq.top().e;
	pq.pop();
	while(!pq.empty())
	{
		node now = pq.top();
		pq.pop();
		if(end<now.s)
		{
			if(end-start<0) len -= end-start;
			else len += end-start;
			start=now.s;
			end=now.e;
		}
		else if(end<now.e) end=now.e;
	}
	if(end-start<0) len -= end-start;
	else len += end-start;
	printf("%d", len);
	
	return 0;
}