#include <stdio.h>
int main(void)
{
	char az[7][17] = {0, };
	int i=0, l=0, j=0;
	
	for(i=0; i<5; i++)
	{
		scanf(" %s", az[i]);
	}
	for(l=0; l<17; l++)
	{
		for(i=0; i<5; i++)
		{
			if((az[i][l]>='0'&&az[i][l]<='9')||(az[i][l]>='a'&&az[i][l]<='z')
			||(az[i][l]>='A'&&az[i][l]<='Z')) printf("%c", az[i][l]);
		}
	}
	return 0;
}