#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[100000];
int top;

void init()
{
	top=-1;
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
	int l, i, t=0, s=0;
	char str[100000];
	
	init();
	scanf("%s", str);
	l = strlen(str);
	for(i=0; i<l; i++)
	{
		if(str[i]=='(') push(str[i]);
		else if(str[i-1]=='(')
		{
			pop();
			push('o');
		}
		else push(str[i]);
	}
	for(i=0; i<l; i++)
	{
		if(stack[i]=='(')
		{
			t++;
			s++;
		}
		else if(stack[i]=='o') t+=s;
		else if(stack[i]==')') s--;
	}
	printf("%d", t);
	
	return 0;
}