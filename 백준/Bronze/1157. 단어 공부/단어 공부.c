#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, l, m=0, mi;
	char s[1000000];
	int n[26]={0};
	scanf("%s", s);
	l = strlen(s);
	for(i=0; i<l; i++)
	{
		if(s[i] > 90) s[i] = s[i] - 32;
		n[s[i]-65]++;
	}
	for(i=0; i<26; i++)
	{
		if(m<n[i]) 
		{
			m = n[i];
			mi = i;
		}
	}
	for(i=0; i<26; i++)
	{
		if(mi == i) continue;
		if(m==n[i])
		{
			printf("?");
			break;
		}
	}
	if(i == 26) printf("%c", mi+'A');
	
	return 0;
}