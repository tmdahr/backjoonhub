#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

typedef struct _node
{
	int m,v;
} node;
struct cmp1
{
	bool operator()(node a, node b)
	{
		return a.v<b.v;
	}
};
struct cmp2
{
	bool operator()(node a, node b)
	{
		return a.m>b.m;
	}
};
struct cmp3
{
	bool operator()(int a, int b)
	{
		return a>b;
	}
};
priority_queue<node, vector<node>, cmp1> jewel;
priority_queue<node, vector<node>, cmp2> jew;
priority_queue<int, vector<int>, cmp3> bag;
int n,k;
long long sum=0;

int main(void)
{
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++)
	{
		int m,v;
		scanf("%d %d", &m, &v);
		jew.push({m,v});
	}
	for(int i=0; i<k; i++)
	{
		int c;
		scanf("%d", &c);
		bag.push(c);
	}
	while(!bag.empty())
	{
		int bc = bag.top();
		bag.pop();
		while(bc>=jew.top().m && !jew.empty())
		{
			jewel.push(jew.top());
			jew.pop();
		}
		if(!jewel.empty())
		{
			sum += jewel.top().v;
			jewel.pop();
		}
	}
	printf("%lld", sum);
	
	return 0;
}