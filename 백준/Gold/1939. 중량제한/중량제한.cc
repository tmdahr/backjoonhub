#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

typedef struct _node
{
	int num, limit;
} node;
vector<node> map[100005];

int n, m;
int Start, End;

bool solution(int weight)
{
	queue<int> q;
	bool visit[100005]={0};
	q.push(Start);
	visit[Start] = true;
	
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now == End) return true;
		
		for(int i = 0; i < map[now].size(); i++)
		{
			if(visit[map[now][i].num] == false)
			{
				if(map[now][i].limit >= weight)
				{
					visit[map[now][i].num] = true;
					q.push(map[now][i].num);
				}
			}
		}
	}
	return false;
}

int main()
{
	int Max=-1;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++)
	{
        int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back({b, c});
		map[b].push_back({a, c});
		Max = max(c,Max);
	}
	scanf("%d %d", &Start, &End);
	
	int left = 1;
	int right = Max;
	
	while (left <= right)
	{
		int mid = (left+right)/2;
		
		if(solution(mid) == true) left=  mid+1;
		else right = mid-1;
	}
	printf("%d", right);
	
	return 0;
}