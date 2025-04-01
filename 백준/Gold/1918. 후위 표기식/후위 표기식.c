#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[105];
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
	printf("%c", stack[top--]);
}

int main(void)
{
	int i, l;
	char s[105];
	
	init();
	scanf("%s", s);
	l = strlen(s);
	
	for(i=0; i<l; i++)
	{
		if(s[i]>='A'&&s[i]<='Z') printf("%c", s[i]);
		else if(s[i]==')')
		{
			for(; stack[top]!='('; ) pop();
			top--;
		}
		else if(s[i]=='+'||s[i]=='-')
		{
			if(stack[top]=='(') push(s[i]);
			else
			{
				while(1)
				{
					if(top==-1||stack[top]=='(') break;
					pop();
				}
				push(s[i]);
			}
		}
		else if(s[i]=='*'||s[i]=='/')
		{
			if(stack[top]=='('||stack[top]=='+'||stack[top]=='-') push(s[i]);
			else
			{
				while(1) 
				{
					if(top==-1||stack[top]=='+'||stack[top]=='-'||stack[top]=='(') break;
					pop();
				}
				push(s[i]);
			}
		}
		else push(s[i]);
	}
	if(top!=-1)
	{
		for(; top>-1; ) pop();
	}
	
	return 0;
}