#include <stdio.h>
int main(void)
{
	char nm[52][52]; 
	char bw[8][9]= {"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};
	char wb[8][9]= {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};
	int i, l, j, k, n, m, c1, c2, v=65;
	
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++)
	{
		scanf("%s", nm[i]);
	}
	for(i=0; i<n-7; i++)
	{
		for(l=0; l<m-7; l++)
		{
			c1=0;
			c2=0;
			for(j=0; j<8; j++)
			{
				for(k=0; k<8; k++)
				{
					if(bw[j][k]!=nm[i+j][l+k]) c1++;
					if(wb[j][k]!=nm[i+j][l+k]) c2++;
				}
			}
			if(v>c1) v=c1;
			if(v>c2) v=c2;
		}
	}
	printf("%d", v);
	
	return 0;
}