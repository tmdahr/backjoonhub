#include <stdio.h>

int map[150][150];

void solution(int h, int w, int n)
{
	
	int num=map[h][w];
	for(int i=h; i<h+n; i++)
		for(int j=w; j<w+n; j++)
			if(num!=map[i][j])
			{
				printf("(");
				solution(h,w,n/2);
				solution(h,w+n/2,n/2);
				solution(h+n/2,w,n/2);
				solution(h+n/2,w+n/2,n/2);
				printf(")");
				return;
			}
	printf("%d", num);
	return;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			scanf("%1d", &map[i][j]);
	solution(1,1,n);
	
	return 0;
}