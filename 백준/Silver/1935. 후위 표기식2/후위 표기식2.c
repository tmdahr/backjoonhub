#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double stack[105];
int top;

void init()
{
	top = -1;
}

void push(double data)
{
	stack[++top] = data;
}

double pop()
{
	return stack[top--];
}

int main(void)
{
	int num, l, i;
	double sn1, sn2, t;
	double n[30];
	char s[105];
	
	init();
	scanf("%d", &num);
	scanf("%s", s);
	l = strlen(s);
	for(i=0; i<num; i++)
	{
		scanf("%lf", &n[i]);
	}
	
	for(i=0; i<l; i++)
	{
		if(s[i]=='+')
		{
			sn1 = pop();
			sn2 = pop();
			push(sn2+sn1);
		}
		else if(s[i]=='-')
		{
			sn1 = pop();
			sn2 = pop();
			push(sn2-sn1);
		}
		else if(s[i]=='*')
		{
			sn1 = pop();
			sn2 = pop();
			push(sn2*sn1);
		}
		else if(s[i]=='/')
		{
			sn1 = pop();
			sn2 = pop();
			push(sn2/sn1);
		}
		else
		{
			num = s[i]-'A';
			t = n[num];
			push(t);
		}
	}
	printf("%.2lf", stack[top]);
	
	return 0;
}