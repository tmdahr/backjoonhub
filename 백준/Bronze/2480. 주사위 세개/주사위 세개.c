#include <stdio.h>

int main(void)
{
	int s1, s2, s3, tkd;
	scanf("%d %d %d", &s1, &s2, &s3);
	
	if(s1 == s2 && s1 == s3)
	{
		tkd = 10000 + s1 * 1000;
		printf("%d", tkd);
	}
	else if(s1 == s2 || s1 == s3 || s2 == s3)
	{
		if(s1 == s2)
		{
			tkd = s1;
		}
		else if(s1 == s3)
		{
			tkd = s1;
		}
		else
		{
			tkd = s2;
		}
		tkd = 1000 + tkd * 100;
		printf("%d", tkd);
	}
	else
	{
		tkd = (s1 > s2) ? s1 : s2;
		tkd = (tkd > s3) ? tkd : s3;
		tkd = tkd * 100;
		printf("%d", tkd);
	}
	
	return 0;
}