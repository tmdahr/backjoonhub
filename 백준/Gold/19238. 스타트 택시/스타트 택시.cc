#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct _pos{
	int y,x,fuel;
}pos;
typedef struct _cus{
	int start_y,start_x;
	int end_y,end_x;
}cus;
pos taxi;
vector<cus> customers;
int customer_num;
int N,M,fuel;
int map[22][22];
int dx[]={0,-1,1,0},dy[]={-1,0,0,1};

bool search()
{
	int arrive=-1;
	
	int visit[22][22]={0};
	queue<pos> q;
	
	visit[taxi.y][taxi.x]=1;
	q.push(taxi);
	
	while(!q.empty())
	{
		pos now = q.front();
		q.pop();
		if(now.fuel<0 && arrive==-1)
			return false;
		if(map[now.y][now.x]==2 && arrive==-1)
			arrive=visit[now.y][now.x];
			
		
		for(int i=0;i<4;i++)
		{
			int yy = now.y+dy[i];
			int xx = now.x+dx[i];
			
			if(0<yy&&yy<=N && 0<xx&&xx<=N)
			{
				if((map[yy][xx]==0 || map[yy][xx]==2) && visit[yy][xx]==0)
				{
					q.push({yy,xx,now.fuel-1});
					visit[yy][xx]=visit[now.y][now.x]+1;
				}
			}
		}
	}
	
	if(arrive==-1)
		return false;
		
	int min=1987654321;
	pos customer;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(map[i][j]==2 && min>visit[i][j])
			{
				min = visit[i][j];
				customer = {i,j,0};
			}
		}
	}
		
	for(int i=0;i<customers.size();i++)
	{
		if(customers[i].start_y==customer.y && customers[i].start_x==customer.x)
			customer_num = i;
	}
	map[customer.y][customer.x]=0;
	taxi={customer.y,customer.x,taxi.fuel-visit[customer.y][customer.x]+1};
	return true;
}

bool ride()
{
	bool visit[22][22]={false};
	queue<pos> q;
	
	visit[taxi.y][taxi.x]=true;
	q.push(taxi);
	
	while(!q.empty())
	{
		pos now = q.front();
		q.pop();
		if(now.fuel<0)
			return false;
		if(customers[customer_num].end_y==now.y && customers[customer_num].end_x==now.x)
		{
			customers.erase(customers.begin()+customer_num,customers.begin()+(customer_num+1));
			taxi = now;
			return true;
		}
		
			
		
		for(int i=0;i<4;i++)
		{
			int yy = now.y+dy[i];
			int xx = now.x+dx[i];
			
			if(0<yy&&yy<=N && 0<xx&&xx<=N)
			{
				if((map[yy][xx]==0 || map[yy][xx]==2) && visit[yy][xx]==false)
				{
					q.push({yy,xx,now.fuel-1});
					visit[yy][xx]=true;
				}
			}
		}
	}
	return false;
}

int solution()
{
	int size = customers.size();
	for(int i=0;i<size;i++)	
	{
		if(!search())
			return -1;
		int prev_fuel = taxi.fuel;
		if(!ride())
			return -1;
		taxi.fuel = taxi.fuel+(prev_fuel-taxi.fuel)*2;
	}
	
	return taxi.fuel;	
}

int main()
{
	scanf("%d%d%d",&N,&M,&fuel);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			scanf("%d",&map[i][j]);
			
	int y,x;
	scanf("%d%d",&y,&x);
	taxi={y,x,fuel};
	
	for(int i=0;i<M;i++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		customers.push_back({a,b,c,d});
		map[a][b]=2;
	}
	printf("%d",solution());
	return 0;
}