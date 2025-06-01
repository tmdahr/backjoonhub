#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

int main()
{
    char str[105];
	while (1)
	{
		fgets(str,105,stdin);
		stack<char> s;
		if (str[0] == '.') break;

        int l = strlen(str)-1;
		for(int i = 0; i < l; i++)
		{
			if(str[i] == '(') s.push('(');
			if(str[i] == '[') s.push('[');
			if(str[i] == ']')
			{
				if(!s.empty() && s.top() == '[') s.pop();
				else
                {
                    printf("no\n");
                    break;
                }
			}
			if(str[i] == ')')
			{
				if(!s.empty() && s.top() == '(') s.pop();
				else
                {
                    printf("no\n");
                    break;
                }
			}
			if(s.empty() && i == l-1) printf("yes\n");
			else if(!s.empty() && i == l-1) printf("no\n");
		}

	}
}