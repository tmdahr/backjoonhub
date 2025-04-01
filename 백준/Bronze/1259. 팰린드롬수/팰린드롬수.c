#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, s, o=0;
	char n[100000], m[100000];
	while (1)
	{
		gets(n);
		if(strcmp(n, "0") == 0) break;
		s = strlen(n);
		for(i=0; i<s; i++) m[i] = n[s-1-i];
		for(i=0; i<s; i++) if(n[i] == m[i]) o++;
		if(o == s) printf("yes\n");
		else printf("no\n");
		o=0;
	}
	
	return 0;
}