#include <stdio.h>
#include <algorithm>
using namespace std;

int l, c, m,n;
int visit[20];
char ch[20], arr[20];

void back(int t, int start)
{
	if(t==l)
	{
		m=0;
		n=0;
		for(int i=0; i<l; i++)
		{
			if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u') m++;
			else if('a'<arr[i]&&arr[i]<='z') n++;
		}
		if(m>=1&&n>=2)
		{
			printf("%s", arr);
			printf("\n");
		}
		return;
	}
	for(int i=start; i<c; i++)
	{
		if(visit[i]==0)
		{
			visit[i]=1;
			arr[t]=ch[i];
			back(t+1,i+1);
			visit[i]=0;
		}
	}
}

int main(void)
{
	scanf("%d %d", &l, &c);
	for(int i=0; i<c; i++) scanf(" %c", &ch[i]);
	sort(ch,ch+c);
	back(0, 0);
}