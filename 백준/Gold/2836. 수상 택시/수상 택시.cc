#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

typedef struct _node
{
	long long f, t;
} node;
struct cmp
{
	bool operator()(node a, node b)
	{
		if(a.f==b.f) return a.t<b.t;
		else return a.f<b.f;
	}
};
priority_queue<node, vector<node>, cmp> pq;

int main(void)
{
	long long n,m,from,to;
	long long len;
	scanf("%lld %lld", &n, &m);
	for(int i=0; i<n; i++)
	{
		scanf("%lld %lld", &from, &to);
		if(from>to) pq.push({from, to});
	}
	len=m;
	if(!pq.empty())
	{
		from=pq.top().f;
		to=pq.top().t;
		pq.pop();
		while(!pq.empty())
		{
			node now = pq.top();
			pq.pop();
			if(now.f>=to)
			{
				if(now.t<to) to = now.t;
			}
			else
			{
				len+=(from-to)*2;
				from=now.f;
				to=now.t;
			}
		}
		len+=(from-to)*2;
	}
	printf("%lld", len);
	
	return 0;
}