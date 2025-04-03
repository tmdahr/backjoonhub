#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, l, st, end, ts;
	char s[100002], t[100002];
	gets(s);
	l = strlen(s);
	st=0;
	for(i=0; i<=l; i++)
	{
		if(i==l&&s[i-1]=='>') i++;
		else if(s[i] == ' '||i==l||s[i]=='<')
		{
			
			ts=0;
			for(end = i-1; st <= end; st++)
			{
				t[st] = s[end-ts];
				ts++;
			}
			t[st] = s[i];
			st=i+1;
		}
		if(s[i]=='<')
		{
			for(; s[i]!='>'; i++) t[i] = s[i];
			t[i] = s[i];
			st=i+1;
		}
	}
	for(i=0; i<l; i++) printf("%c", t[i]);
	
	return 0;
}