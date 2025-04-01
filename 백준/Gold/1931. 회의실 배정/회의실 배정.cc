#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

typedef struct _node
{
	int start,end;
} node;
struct cmp
{
	bool operator()(node a, node b)
	{
		if(a.end == b.end) return a.start>b.start;
		else return a.end>b.end;
	}
};
priority_queue<node, vector<node>, cmp> pq;

int main(void)
{
	int n, num=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int s,e;
		scanf("%d %d", &s, &e);
		pq.push({s,e});
	}
	node time = pq.top();
	pq.pop();
	num++;
	while(!pq.empty())
	{
		if(time.end<=pq.top().start)
		{
			num++;
			time = pq.top();
		}
		pq.pop();
	}
	printf("%d", num);
	
	return 0;
}