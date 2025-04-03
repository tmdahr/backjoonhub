#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TURE 1
#define FALSE 0
#define QUE_LEN 10005

typedef int Data;
typedef struct _cQueue
{
	int size;
	int front;
	int rear;
	Data queArr[QUE_LEN];
} CQueue;
typedef CQueue Queue;

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);
void Push(Queue *pq, Data data);
Data Pop(Queue *pq);
Data Qsize(Queue *pq);
Data Qfront(Queue *pq);
Data Qback(Queue *pq);
int NextPosIdx(int pos);

int main(void)
{
	Queue q;
	QueueInit(&q);
	int n, i, d;
	char s[20];
	
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf(" %s", s);
		if(strcmp(s, "push") == 0)
		{
			scanf(" %d", &d);
			Push(&q, d);
		}
		else if(strcmp(s, "pop") == 0) printf("%d\n", Pop(&q));
		else if(strcmp(s, "size") == 0) printf("%d\n", Qsize(&q));
		else if(strcmp(s, "empty") == 0) printf("%d\n", QIsEmpty(&q));
		else if(strcmp(s, "front") == 0) printf("%d\n", Qfront(&q));
		else if(strcmp(s, "back") == 0) printf("%d\n", Qback(&q));
	}
	
	return 0;
}

void QueueInit(Queue *pq)
{
	pq->rear=0;
	pq->front=0;
}
int QIsEmpty(Queue *pq)
{
	if(pq->rear==pq->front) return TURE;
	else return FALSE;
}
int NextPosIdx(int pos)
{
	if(pos==QUE_LEN-1) return 0;
	else return pos+1;
}
void Push(Queue *pq, Data data)
{
	pq->size++;
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}
Data Pop(Queue *pq)
{
	if(QIsEmpty(pq)) return -1;
	else
	{
		pq->size--;
		pq->front = NextPosIdx(pq->front);
		return pq->queArr[pq->front];
	}
}
Data Qsize(Queue *pq)
{
	return pq->size;
}
Data Qfront(Queue *pq)
{
	if(QIsEmpty(pq)) return -1;
	else
	{
		return pq->queArr[NextPosIdx(pq->front)];
	}
}
Data Qback(Queue *pq)
{
	if(QIsEmpty(pq)) return -1;
	else
	{
		return pq->queArr[pq->rear];
	}
}