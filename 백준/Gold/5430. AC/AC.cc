#include <stdio.h>
#include <string.h>
using namespace std;

char p[100005];
int num[100005];
int t,n,r;

void input()
{
	char temp;
	scanf(" %c",&temp);//[
	for(int i=0;i<n;i++)
	{
		scanf("%d", &num[i]);
		if(i!=n-1) scanf(" %c",&temp);
	}
	scanf(" %c",&temp);//]
}

int main(void)
{
	scanf("%d", &t);
	while(t>0)
	{
		scanf(" %s", p);
		scanf("%d", &n);
		input();
		int l = strlen(p);
		int start=0;
		r=0;
		for(int i=0; i<l; i++)
		{
			if(p[i]=='R') r++;
			else if(r%2==1) n--;
			else start++;
		}
		if(n-start<0) printf("error\n");
		else
		{
			printf("[");
			if(r%2==1)
			{
				for(int i=n-1; i>=start; i--)
				{
					printf("%d", num[i]);
					if(i!=start) printf(",");
				}
			}
			else
			{
				for(int i=start; i<n; i++)
				{
					printf("%d", num[i]);
					if(i!=n-1) printf(",");
				}
			}
			printf("]\n");
		}
		t--;
	}
}