#define TRUE 1
#define FALSE 0
#define STACK_LEN 100002
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Data;

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack * pstack);
void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);

int main(void)
{
	Stack stack;
	int n, i, t=0, l;
	char s[100002];
	
	scanf("%d", &n);
	while(n>0)
	{
		scanf("%s", s);
		l = strlen(s);
		StackInit(&stack);
		if(l%2!=1)
		{
			for(i=0; i<l; i++)
			{
				if(stack.stackArr[stack.topIndex] == s[i]) SPop(&stack);
				else SPush(&stack, s[i]);
			}
			if(stack.topIndex==-1) t++;
		}
		
		n--;
	}
	printf("%d", t);
	
	return 0;
}

void StackInit(Stack * pstack)
{
	pstack->topIndex = -1;
}

void SPush(Stack * pstack, Data data)
{
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack)
{
	int rIdx;
	
	rIdx = pstack->topIndex;
	pstack->topIndex -= 1;
	
	return pstack->stackArr[rIdx];
}