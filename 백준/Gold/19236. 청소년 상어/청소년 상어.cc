#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct _fish
{
	int r, c, d;
	bool l;
} fish;

int answer=0;
int map[5][5];
fish fl[20];
int dr[] = {0,-1,-1,0,1,1,1,0,-1}, dc[] = {0,0,-1,-1,-1,0,1,1,1};

void copy_map(int a[5][5], int b[5][5], fish c[], fish d[])
{
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			a[i][j]=b[i][j];
	for(int i=1; i<=16; i++) c[i]=d[i];
}

void swap_fish(int i, int j)
{
	fish temp = fl[i];
	fl[i].r = fl[j].r;
	fl[i].c = fl[j].c;
	fl[j].r = temp.r;
	fl[j].c = temp.c;
}

void move_fish()
{
	for(int i=1; i<=16; i++)
	{
		if(fl[i].l==false) continue;
		int r = fl[i].r;
		int c = fl[i].c;
		int d = fl[i].d;
		
		int rr = r+dr[d];
		int cc = c+dc[d];
		bool l = false;
		if(0<=rr&&rr<4 && 0<=cc&&cc<4)
		{
			if(map[rr][cc]==0)
			{
				l = true;
				fl[i].r = rr;
				fl[i].c = cc;
				map[rr][cc] = i;
				map[r][c]=0;
			}
			else if(map[rr][cc] != -1)
			{
				l = true;
				swap_fish(i, map[rr][cc]);
				swap(map[r][c], map[rr][cc]);
			}
		}
		
		if(l==false)
		{
			int od = d+1;
			if(od==9) od=1;
			int rr = r+dr[od];
			int cc = c+dc[od];
			while(od!=d)
			{
				if(0<=rr&&rr<4 && 0<=cc&&cc<4)
				{
					if(map[rr][cc]==0)
					{
						fl[i].r = rr;
						fl[i].c = cc;
						fl[i].d = od;
						map[rr][cc] = i;
						map[r][c]=0;
						break;
					}
					else if(map[rr][cc] != -1)
					{
						swap_fish(i, map[rr][cc]);
						swap(map[r][c], map[rr][cc]);
						fl[i].d = od;
						break;
					}
				}
				od++;
				if(od==9) od=1;
				rr = r+dr[od];
				cc = c+dc[od];
			}
		}
	}
}

void shark(int r, int c, int rr, int cc, int num, bool tf)
{
	if(tf==true)
	{
		map[r][c]=0;
		map[rr][cc]=-1;
		fl[num].l = false;
	}
	else
	{
		map[r][c]=-1;
		map[rr][cc]=num;
		fl[num].l = true;
	}
}

void dfs(int r, int c, int sum, int d)
{
	answer = max(answer, sum);
	int cm[5][5];
	fish cl[20];
	copy_map(cm, map, cl, fl);
	
	move_fish();
	
	for(int i=1; i<4; i++)
	{
		int rr = r+dr[d]*i;
		int cc = c+dc[d]*i;
		if(0<=rr&&rr<4 && 0<=cc&&cc<4)
		{
			if(map[rr][cc]==0) continue;
			int num = map[rr][cc];
			int od = fl[num].d;
			
			shark(r,c,rr,cc,num,true);
//			for(int j=0; j<4; j++)
//			{
//				for(int k=0; k<4; k++)
//				{
//					printf("%d ", map[j][k]);
//				}
//				puts("");
//			}
//			printf("%d", sum+num);
//			puts("");
			dfs(rr,cc,sum+num,od);
			shark(r,c,rr,cc,num,false);
		}
		else break;
	}
	copy_map(map, cm, fl, cl);
}

int main(void)
{
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			map[i][j] = a;
			fl[a] = {i,j,b,true};
		}
	int num = map[0][0];
	int d = fl[num].d;
	fl[num].l = false;
	map[0][0]=-1;
	dfs(0,0,num,d);
	printf("%d", answer);
	
	return 0;
}