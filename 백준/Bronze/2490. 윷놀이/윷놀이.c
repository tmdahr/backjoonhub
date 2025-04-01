#include <stdio.h>
int main(void)
{
	int i, n, m;
	int dbc[4];
	for(i = 0; i < 3; i++)
	{
		scanf("%d%d%d%d", &dbc[0], &dbc[1], &dbc[3], &dbc[4]);
		m = dbc[0] + dbc[1] + dbc[3] + dbc[4];
		if(m == 4)
		{
			printf("E\n");
		}
		else if(m == 3)
		{
			printf("A\n");
		}
		else if(m == 2)
		{
			printf("B\n");
		}
		else if(m == 1)
		{
			printf("C\n");
		}
		else
		{
			printf("D\n");
		}
	}
	
	return 0;
}