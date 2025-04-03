#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, l;
	char s[500];
	
	for(i=0; s!="END"; i++)
	{
		gets(s);
		if(strcmp(s,"END")==0) break;
		for(l = strlen(s)-1; l>=0; l--) printf("%c", s[l]);
		printf("\n");
	}
	
	return 0;
}