#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[100000];
int top;
char pp[200000];
int t;

void init()
{
	top=-1;
	t=-1;
}

void push(data)
{
	pp[++t] = '+';
	stack[++top] = data;
}

void pop()
{
	pp[++t] = '-';
	top--;
}

int main(void)
{
	int n, i, l=0;
	int str[100000];
	char o='O';
	
	init();
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &str[i]);
	}
	for(i=0; i<n; i++)
	{
		if(str[i]>stack[top])
		{
			while(l!=str[i])
			{
				l++;
				push(l);
			}
		}
		if(str[i]==stack[top]) pop();
		else if(str[i]<stack[top])
		{
			printf("NO");
			o = 'N';
			break;
		}
	}
	if(o!='N')
	{
		for(i=0; i<=t; i++) printf("%c\n", pp[i]);
	}
	
	return 0;
}