#include <stdio.h>
#include <queue>
using namespace std;

int n,m=0;
void move(int map[25][25], int d)
{
	queue<int> q;
	
	switch(d)
	{
		case 0:
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					if(map[i][j]!=0) q.push(map[i][j]);
					map[i][j]=0;
				}
				int j=0;
				while(!q.empty())
				{
					int data=q.front();
					q.pop();
					if(map[i][j]==0) map[i][j]=data;
					else if(map[i][j]==data) map[i][j++]*=2;
					else map[i][++j]=data;
				}
			}
			break;
		case 1:
			for(int i=0; i<n; i++)
			{
				for(int j=n-1; j>=0; j--)
				{
					if(map[i][j]!=0) q.push(map[i][j]);
					map[i][j]=0;
				}
				int j=n-1;
				while(!q.empty())
				{
					int data=q.front();
					q.pop();
					if(map[i][j]==0) map[i][j]=data;
					else if(map[i][j]==data) map[i][j--]*=2;
					else map[i][--j]=data;
				}
			}
			break;
		case 2:
			for(int j=0; j<n; j++)
			{
				for(int i=0; i<n; i++)
				{
					if(map[i][j]!=0) q.push(map[i][j]);
					map[i][j]=0;
				}
				int i=0;
				while(!q.empty())
				{
					int data=q.front();
					q.pop();
					if(map[i][j]==0) map[i][j]=data;
					else if(map[i][j]==data) map[i++][j]*=2;
					else map[++i][j]=data;
				}
			}
			break;
		case 3:
			for(int j=0; j<n; j++)
			{
				for(int i=n-1; i>=0; i--)
				{
					if(map[i][j]!=0) q.push(map[i][j]);
					map[i][j]=0;
				}
				int i=n-1;
				while(!q.empty())
				{
					int data=q.front();
					q.pop();
					if(map[i][j]==0) map[i][j]=data;
					else if(map[i][j]==data) map[i--][j]*=2;
					else map[--i][j]=data;
				}
			}
			break;
	}
}

void find(int map[25][25], int count)
{
	if(count==5)
	{
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
					m = max(m,map[i][j]);
		return ;
	}
	
	for(int l=0; l<4; l++)
	{
		int cm[25][25];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cm[i][j] = map[i][j];
		move(cm, l);
		find(cm, count+1);
	}
}

int main(void)
{
	int map[25][25]={0,};
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &map[i][j]);
	find(map, 0);
	printf("%d", m);
	return 0;
}