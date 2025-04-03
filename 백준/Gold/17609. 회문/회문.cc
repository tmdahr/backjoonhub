#include <stdio.h>
#include <string.h>

char s[100005];

int left(int len, int j)
{
	int o=0;
	for(int i=0; i<j; i++)
	{
		if(s[i+o]!=s[len-i])
		{
			o++;
			if(s[i+o]!=s[len-i]||o>1) return 2;
		}	
	}
	if(o!=0) return 1;
	else return 0;
}

int right(int len, int j)
{
	int o=0;
	for(int i=0; i<j; i++)
	{
		if(s[i]!=s[len-i-o])
		{
			o++;
			if(s[i]!=s[len-i-o]||o>1) return 2;
		}
	}
	if(o!=0) return 1;
	else return 0;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i=0; i<t; i++)
	{
		scanf(" %s", s);
		int len = strlen(s);
		int j = len/2+len%2;
		len--;
		int l = left(len, j);
		int r = right(len, j);
		if(l==0||r==0) printf("0\n");
		else if(l==1||r==1) printf("1\n");
		else printf("2\n");
	}
	
	return 0;
}