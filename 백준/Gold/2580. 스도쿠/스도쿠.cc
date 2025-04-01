#include <stdio.h>

typedef struct _node
{
	int h,w;
} node;
int map[10][10];
node o[100];
int c=0, end=0;

bool ck1(int h, int w, int num)
{
	for(int i=0; i<9; i++)
	{
		if(map[h][i]==num) return false;
	}
	return true;
}
bool ck2(int h, int w, int num)
{
	for(int i=0; i<9; i++)
	{
		if(map[i][w]==num) return false;
	}
	return true;
}
bool ck3(int h, int w, int num)
{
	int hh = h/3*3;
	int ww = w/3*3;
	for(int i=hh; i<hh+3; i++)
	{
		for(int j=ww; j<ww+3; j++)
		{
			if(map[i][j]==num) return false;
		}
	}
	return true;
}

void solution(int n)
{
	if(n==c)
	{
		end=1;
		for(int i=0; i<9; i++)
		{
			for(int j=0; j<9; j++)
			{
				printf("%d ", map[i][j]);
			}
			puts("");
		}
		return;
	}
	
	int hh=o[n].h;
	int ww=o[n].w;
	for(int i=1; i<=9; i++)
	{
		if(ck1(hh,ww,i)&&ck2(hh,ww,i)&&ck3(hh,ww,i))
		{
			map[hh][ww]=i;
			solution(n+1);
			if(end==1) break;
			map[hh][ww]=0;
		}
	}
}

int main(void)
{
	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j]==0) o[c++] = {i,j};
		}
	solution(0);
	return 0;
}