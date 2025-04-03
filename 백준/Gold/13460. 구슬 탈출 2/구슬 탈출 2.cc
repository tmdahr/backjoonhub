#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct _ball {
	int d;
	int red_y, red_x;
	int blue_y, blue_x;
}ball;

int N, M;
char map[15][15];
bool visit[15][15][15][15];

int end_x, end_y;
int s_rx, s_ry, s_bx, s_by;
int ans=-1;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
// 하 우 상 좌
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'O')
			{
				end_y = i;
				end_x = j;
			}
			if (map[i][j] == 'R')
			{
				s_ry = i;
				s_rx = j;
			}
			if (map[i][j] == 'B')
			{
				s_by = i;
				s_bx = j;
			}
		}

	queue<ball> q;
	q.push({ 0,s_ry,s_rx,s_by,s_bx });
	visit[s_ry][s_rx][s_by][s_bx] = true;

	while (!q.empty())
	{
		ball now = q.front();
		q.pop();

		if (now.d > 10)
			break;
		if (map[now.red_y][now.red_x]=='O')
		{
			ans = now.d;
			break;
		}
			
		for (int i = 0; i < 4; i++)
		{
			int red_yy = now.red_y;
			int red_xx = now.red_x;
			int blue_yy = now.blue_y;
			int blue_xx = now.blue_x;

			while (1)
			{
				red_yy += dy[i];
				red_xx += dx[i];

				if (map[red_yy][red_xx] == '#')
				{
					red_yy -= dy[i];
					red_xx -= dx[i];
					break;
				}
				else if (map[red_yy][red_xx] == 'O')
					break;
			}
			while (1)
			{
				blue_yy += dy[i];
				blue_xx += dx[i];

				if (map[blue_yy][blue_xx] == '#')
				{
					blue_yy -= dy[i];
					blue_xx -= dx[i];
					break;
				}
				else if (map[blue_yy][blue_xx] == 'O')
					break;
			}

			if (blue_yy == end_y && blue_xx == end_x)
				continue;
			if (red_yy == blue_yy && red_xx == blue_xx)
			{
				if (i == 0)
					now.red_y < now.blue_y ? red_yy-- : blue_yy--;
				if (i == 1)
					now.red_x < now.blue_x ? red_xx-- : blue_xx--;
				if (i == 2)
					now.red_y < now.blue_y ? blue_yy++ : red_yy++;
				if (i == 3)
					now.red_x < now.blue_x ? blue_xx++ : red_xx++;
					
			}
			if (!visit[red_yy][red_xx][blue_yy][blue_xx])
			{
				q.push({ now.d + 1,red_yy,red_xx,blue_yy,blue_xx });
				visit[red_yy][red_xx][blue_yy][blue_xx] = 1;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
