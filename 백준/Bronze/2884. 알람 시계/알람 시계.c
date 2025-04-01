#include <stdio.h>

int main(void)
{
	int H, M;
	scanf("%d %d", &H, &M);
	M = H * 60 + M - 45;
	if(M < 0)
	{
		M = 60 + M;
		if(H < 1)
		{
			H = 23 - H;
		}
		else
		{
			H = M / 60;
		}
	}
	else
	{
		H = M / 60;
	}
	M = M % 60;
	printf("%d %d", H, M);
	
	return 0;
}