#define TRUE 1
#define FALSE 0
#define STACK_LEN 10002
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Data;

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);
void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

int size(Stack * pstack);
int top(Stack * pstack);

int main(void)
{
	Stack stack;
	StackInit(&stack);
	
	int n, i, x;
	char st[15];
	
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%s", st);
		
		if(strcmp(st, "push")==0)
		{
			scanf("%d", &x);
			SPush(&stack, x);
		}
		else if(strcmp(st, "top")==0)
		{
			printf("%d\n", top(&stack));
		}
		else if(strcmp(st, "size")==0)
		{
			printf("%d\n", size(&stack));
		}
		else if(strcmp(st, "empty")==0)
		{
			printf("%d\n", SIsEmpty(&stack));
		}
		else if(strcmp(st, "pop")==0)
		{
			printf("%d\n", SPop(&stack));
		}
	}
	
	return 0;
}

void StackInit(Stack * pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack)
{
	if(pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack)
{
	int rIdx;
	
	if(SIsEmpty(pstack)) return -1;
	else
	{
		rIdx = pstack->topIndex;
		pstack->topIndex -= 1;
		
		return pstack->stackArr[rIdx];
	}
}

Data SPeek(Stack * pstack)
{
	if(SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	
	return pstack->stackArr[pstack->topIndex];
}

int top(Stack * pstack)
{
	if(SIsEmpty(pstack)) return -1;
	else return pstack->stackArr[pstack->topIndex];
}

int size(Stack * pstack)
{
	return pstack->topIndex+1;
}