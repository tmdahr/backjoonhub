#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, l, t=0;
	char s[20];
	
	scanf("%s", s);
	l = strlen(s);
	for(i=0; i<l; i++)
	{
		if(s[i]-'A'>=0&&s[i]-'A'<=2) t= t+3;
		else if(s[i]-'D'>=0&&s[i]-'D'<=2) t= t+4;
		else if(s[i]-'G'>=0&&s[i]-'G'<=2) t= t+5;
		else if(s[i]-'J'>=0&&s[i]-'J'<=2) t= t+6;
		else if(s[i]-'M'>=0&&s[i]-'M'<=2) t= t+7;
		else if(s[i]-'P'>=0&&s[i]-'P'<=3) t= t+8;
		else if(s[i]-'T'>=0&&s[i]-'T'<=2) t= t+9;
		else if(s[i]-'W'>=0&&s[i]-'W'<=3) t= t+10;
	}
	printf("%d", t);
	
	return 0;
}