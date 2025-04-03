#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[52];
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
	int t, l, i;
	char str[52];
	
	scanf("%d", &t);
	while(t>0)
	{
		scanf("%s", str);
		l = strlen(str);
		init();
		if(l%2==0)
		{
			for(i=0; i<l; i++)
			{
				if(top==-1) push(str[i]);
				else if(stack[top]==str[i]) push(str[i]);
				else if(stack[top]=='('&&str[i]==')')pop();
			}
			if(top==-1) printf("YES\n");
			else printf("NO\n");
		}
		else printf("NO\n");
		
		t--;
	}
	
	return 0;
}