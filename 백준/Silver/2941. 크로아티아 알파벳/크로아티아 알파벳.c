#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, l, t=0;
	char s[105];
	scanf("%s", s);
	l = strlen(s);
	
	for(i=0; i<l; i++)
	{
		t++;
		if(s[i]=='=')
		{
			t--;
			if(s[i-1]=='z'&&s[i-2]=='d') t--;
		}
		if(s[i]=='j'&&s[i-1]=='n') t--;
		if(s[i]=='j'&&s[i-1]=='l') t--;
		if(s[i]=='-') t--;
	}
	
	printf("%d", t);
	
	return 0;
}