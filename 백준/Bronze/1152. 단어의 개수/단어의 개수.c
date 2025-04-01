#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, l, n=1;
	char s[1000000];
	gets(s);
	l = strlen(s);
	if(s[0] == 32) n--;
	for(i=0; i<l; i++) if(s[i] == 32) n++;
	if(s[i-1] == 32) n--;
	printf("%d", n);
	
	return 0;
}