#include <stdio.h>

int map[150][150];
int wh=0, b=0;

void solution(int h, int w, int n)
{
	int wb=map[h][w];
	for(int i=h; i<h+n; i++)
		for(int j=w; j<w+n; j++)
			if(wb!=map[i][j])
			{
				solution(h,w,n/2);
				solution(h,w+n/2,n/2);
				solution(h+n/2,w,n/2);
				solution(h+n/2,w+n/2,n/2);
				return;
			}
	if(wb==0) wh++;
	else b++;
	return;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			scanf("%d", &map[i][j]);
	solution(1,1,n);
	printf("%d\n", wh);
	printf("%d\n", b);
	
	return 0;
}