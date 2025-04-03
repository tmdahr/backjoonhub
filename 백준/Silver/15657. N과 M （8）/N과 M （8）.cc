#include <stdio.h>
#include <algorithm>
using namespace std;

int n,m;
int num[10], visit[10], arr[10];

void back(int stop, int start)
{
	if(stop==m)
	{
		for(int i=0; i<stop; i++) printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for(int i=start-1; i<n; i++)
	{
		arr[stop]=num[i];
		back(stop+1, i+1);
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) scanf("%d", &num[i]);
	sort(num,num+n);
	back(0, 1);
}