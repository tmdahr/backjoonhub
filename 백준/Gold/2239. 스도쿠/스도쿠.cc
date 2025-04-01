#include <stdio.h>

typedef struct _node
{
	int h, w;
} node;
int map[10][10];
node o[100];
int c=0, end=0;

bool ck1(int num, int h)
{
	for(int i=0; i<9; i++) if(map[h][i]==num) return false;
	return true;
}
bool ck2(int num, int w)
{
	for(int i=0; i<9; i++) if(map[i][w]==num) return false;
	return true;
}
bool ck3(int num, int h, int w)
{
	int hh=h/3*3;
	int ww=w/3*3;
	for(int i=hh; i<hh+3; i++)
		for(int j=ww; j<ww+3; j++)
			if(map[i][j]==num) return false;
	return true;
}

void solution(int num)
{
	if(num==c)
	{
		end=1;
		for(int i=0; i<9; i++)
		{
			for(int j=0; j<9; j++) printf("%d", map[i][j]);
			puts("");
		}
		return;
	}
	int h=o[num].h;
	int w=o[num].w;
	for(int i=1; i<10; i++)
	{
		if(ck1(i,h)&&ck2(i,w)&&ck3(i,h,w))
		{
			map[h][w]=i;
			solution(num+1);
			if(end==1) return;
			map[h][w]=0;
		}
	}
}

int main(void)
{
	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
		{
			scanf("%1d", &map[i][j]);
			if(map[i][j]==0) o[c++]={i,j};
		}
	solution(0);
	return 0;
}