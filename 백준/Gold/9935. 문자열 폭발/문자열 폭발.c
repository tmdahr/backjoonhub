#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[1000000];
int top;

void init()
{
	top = -1;
}

void push(char data)
{
	stack[++top] = data;
}

void pop()
{
	top--;
}

int main(void)
{
	int i, l, tl, j;
	char str[1000000];
	char t[40];
	
	init();
	scanf("%s", str);
	l = strlen(str);
	scanf("%s", t);
	tl = strlen(t);
	for(i=0; i<=l; i++)
	{
		
		push(str[i]);
		if(str[i]==t[tl-1])
		{
			for(j=1; j<tl; j++)
			{
				if(stack[top-j]!=t[tl-1-j]) break;
			}
			if(j==tl)
			{
				for(j=0; j<tl; j++) pop();
			}
		}
	}
	if(top==0) printf("FRULA");
	else printf("%s", stack);
	
	return 0;
}