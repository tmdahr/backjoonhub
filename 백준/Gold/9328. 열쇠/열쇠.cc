#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 102
#define SIZE 1000000

typedef struct
{
    int r, c;
} node;
node q[SIZE];

char map[MAX][MAX];
int visit[MAX][MAX];
int h, w;
int dr[4] = {-1,1,0,0}, dc[4] = {0,0,-1,1};
int front, rear;

int has_key[26];
node doors[26][SIZE];
int door_cnt[26];

void enqueue(int r, int c) {q[rear++] = (node){r, c};}
node dequeue() {return q[front++];}

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &h, &w);
        for(int i=0; i<h+2; i++)
        {
            for(int j=0; j<w+2; j++)
            {
                map[i][j] = '.';
                visit[i][j] = 0;
            }
        }
        char line[MAX];
        for(int i=1; i<=h; i++)
        {
            scanf("%s", line);
            for(int j=1; j<=w; j++) map[i][j] = line[j-1];
        }
        memset(has_key, 0, sizeof(has_key));
        memset(door_cnt, 0, sizeof(door_cnt));
        char keys[MAX];
        scanf("%s", keys);
        if(keys[0] != '0')
        {
            for(int i=0; keys[i]; i++) has_key[keys[i]-'a'] = 1;
        }

        int docs = 0;
        front = rear = 0;
        enqueue(0, 0);
        visit[0][0] = 1;

        while(front < rear)
        {
            node p = dequeue();
            for(int d=0; d<4; d++)
            {
                int nr = p.r + dr[d];
                int nc = p.c + dc[d];
                if(nr<0 || nr>=h+2 || nc<0 || nc>=w+2) continue;
                if(visit[nr][nc] || map[nr][nc] == '*') continue;
                
                char ch = map[nr][nc];
                visit[nr][nc] = 1;
                if(ch >= 'A' && ch <= 'Z')
                {
                    int idx = ch - 'A';
                    if(has_key[idx])
                    {
                        map[nr][nc] = '.';
                        enqueue(nr, nc);
                    }
                    else doors[idx][door_cnt[idx]++] = (node){nr, nc};
                }
                else if(ch >= 'a' && ch <= 'z')
                {
                    int idx = ch - 'a';
                    has_key[idx] = 1;
                    map[nr][nc] = '.';
                    enqueue(nr, nc);
                    for(int i=0; i<door_cnt[idx]; i++)
                    {
                        node dp = doors[idx][i];
                        visit[dp.r][dp.c] = 1;
                        enqueue(dp.r, dp.c);
                    }
                    door_cnt[idx] = 0;
                }
                else if(ch == '$')
                {
                    docs++;
                    map[nr][nc] = '.';
                    enqueue(nr, nc);
                }
                else enqueue(nr, nc);
            }
        }
        printf("%d\n", docs);
    }
    return 0;
}
