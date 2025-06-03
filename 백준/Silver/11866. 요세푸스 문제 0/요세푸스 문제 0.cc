#include <stdio.h>
#include <queue>
using namespace std;

int n, k;
queue<int> q;

int main(void)
{
	int i;
	scanf("%d %d", &n, &k);
	for(i = 1; i <= n; i++)
		q.push(i);
	printf("<");
	while(!q.empty())
	{
		for(i = 1; i < k; i++)
		{
			q.push(q.front());
			q.pop();
		}
		printf("%d", q.front());
		if(q.size() != 1)
			printf(", ");
		q.pop();
	}
	printf(">");
	return 0;
}