#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUE_LEN 10

typedef char Data;
typedef struct _cQueue
{
	int start;
	Data queArr[QUE_LEN];
} CQueue;
typedef CQueue Queue;

void Push(Queue *pq);
Data Pop(Queue *pq);
void Qscan(Queue *pq);

int main(void)
{
	int n, i;
	Queue q;
	
	Qscan(&q);
	scanf("%d", &n);
	for(i=0; i<n; i++) Push(&q);
	for(i=0; i<10; i++) Pop(&q);
	
	return 0;
}

void Qscan(Queue *pq)
{
	char s[12];
	int l, i;
	pq->start=0;
	strcpy(s, "SciComLove");
	l = strlen(s);
	for(i=0; i<l; i++)
	{
		pq->queArr[pq->start] = s[i];
		Push(pq);
	}
	
	pq->start = 0;
}
void Push(Queue *pq)
{
	if(pq->start==QUE_LEN-1) pq->start = 0;
	else pq->start++;
}
Data Pop(Queue *pq)
{
	printf("%c", pq->queArr[pq->start]);
	Push(pq);
}