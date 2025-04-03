#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct _node
{
	int left, right;
} node;
struct com
{
	bool operator()(node a, node b)
	{
		if(a.right==b.right) return a.left>b.left;
		else return a.right>b.right;
	}
};
struct cmp
{
	bool operator()(int a, int b)
	{
		return a>b;
	}
};
priority_queue<int, vector<int>, cmp> pq;
priority_queue<node, vector<node>, com> arr;

int main(void)
{
	int n,d,cnt=0,max=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int h,o;
		scanf("%d %d", &h, &o);
		if(h<o) arr.push({h,o});
		else arr.push({o,h});
	}
	scanf("%d", &d);
	
	while(!arr.empty())
	{
		node now = arr.top();
		arr.pop();
		int end = now.right;
		int start = now.left;
		int len = end-d;
		
		while(!pq.empty())
		{
			if(len<=pq.top()) break;
			pq.pop();
			cnt--;
		}
		if(start>=len)
		{
			cnt++;
			pq.push(start);
			if(max<cnt) max=cnt;
		}
	}
	printf("%d", max);
	
	return 0;
}