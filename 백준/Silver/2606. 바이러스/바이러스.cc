#include <stdio.h>

int map[102][102] = {0, }; // 네트워크로 연결된 컴퓨터들을 1로 표시할 배열
int visit[102] = {0, }; // 이미 방문한 컴퓨터에 1로 표시할 배열
int N, M, count=0; // 컴퓨터 수, 연결된 수, 감염된 컴퓨터 수

void DFS(int v) // DFS와 BFS 둘 중 아무거나 가능하지만 더 간단하다고 느낀 DFS 구현
{
	visit[v]=1; // 이미 방문한 컴퓨터에 1로 표시
	for(int i=1; i<=N; i++)
	{
		if(map[v][i]==1&&visit[i]==0) // 네트워크로 연결되어 있고, 방문한 적 없다면
		{
			count++; // 감염된 컴퓨터 수 1 증가
			DFS(i); // 감염된 컴퓨터 기준으로 DFS 
		}
	}
}

int main(void)
{
	int from, to;
	
	scanf("%d", &N); // 모든 컴퓨터 수
	scanf("%d", &M); // 네트워크로 연결된 수
	for(int i=0; i<M; i++)
	{
		scanf("%d %d", &from, &to); // 네트워크로 연결된 컴퓨터 입력받아
		map[from][to]=1; // 배열에서 1로 표시
		map[to][from]=1;
	}
	
	DFS(1); // 감염된 컴퓨터인 1번으로 DFS 시작
	printf("%d", count); // 감염된 컴퓨터 수 출력
	
	return 0;
}