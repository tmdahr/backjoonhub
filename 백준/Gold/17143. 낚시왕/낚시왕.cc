#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

typedef struct _node
{
	int r,c,s,d,z;
} node;
typedef struct _mapdata
{
	int s,d,z,n;
} mapdata;
queue<node> shark;
mapdata map[105][105];

int main(void)
{
	int r,c,m,sum=0;
	scanf("%d %d %d", &r, &c, &m);
	for(int i=0; i<m; i++)
	{
		node sh;
		scanf("%d %d %d %d %d",&sh.r,&sh.c,&sh.s,&sh.d,&sh.z);
		shark.push(sh);
	}//입력
	
	for(int p=1; p<=c; p++)
	{
		node cs, sh;
		cs.r = r+1;
		for(int i=0; i<m; i++)
		{
			sh = shark.front();
			shark.pop();
			if(sh.c==p&&cs.r>sh.r)
			{
				if(cs.r!=r+1) shark.push(cs);
				cs = sh;
			}
			else shark.push(sh);
		}
		if(cs.r!=r+1)
		{
			m--;
			sum+=cs.z;//상어 잡기
		}
		while(!shark.empty())
		{
			sh = shark.front();
			shark.pop();
			if(sh.d==1)
			{
				if(sh.s<sh.r) sh.r-=sh.s;
				else
				{
					int s = sh.s-sh.r+1;
					int d = s/(r-1)+1;
					s = s%(r-1);
					if(d%2==1)
					{
						sh.d=2;
						sh.r = 1+s;
					}
					else sh.r=r-s;
				}
			}
			else if(sh.d==2)
			{
				if(sh.r+sh.s<r) sh.r+=sh.s;
				else
				{
					int s = sh.s-(r-sh.r);
					int d = s/(r-1)+1;
					s = s%(r-1);
					if(d%2==1)
					{
						sh.d=1;
						sh.r = r-s;
					}
					else sh.r=1+s;
				}
			}
			else if(sh.d==3)
			{
				if(sh.c+sh.s<c) sh.c+=sh.s;
				else
				{
					int s = sh.s-(c-sh.c);
					int d = s/(c-1)+1;
					s = s%(c-1);
					if(d%2==1)
					{
						sh.d=4;
						sh.c = c-s;
					}
					else sh.c=1+s;
				}
			}
			else
			{
				if(sh.s<sh.c) sh.c-=sh.s;
				else
				{
					int s = sh.s-sh.c+1;
					int d = s/(c-1)+1;
					s = s%(c-1);
					if(d%2==1)
					{
						sh.d=3;
						sh.c = 1+s;
					}
					else sh.c=c-s;
				}
			}
			if(map[sh.r][sh.c].z<sh.z || map[sh.r][sh.c].n<p)
				map[sh.r][sh.c]={sh.s,sh.d,sh.z,p};
			else m--;
		}
		for(int i=1; i<=r; i++)
			for(int j=1; j<=c; j++)
				if(map[i][j].n==p)
				{
					mapdata d = map[i][j];
					shark.push({i,j,d.s,d.d,d.z});
				}//상어 이동
	}
	printf("%d", sum);
	
	return 0;
}