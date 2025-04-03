#include <stdio.h>
#include <string.h>
int main(void)
{
	int num, i, length, l, word_first, word_last, e;
	char s[1000], st[20];
	scanf("%d", &num);
	getchar();
	for (i=0; i<num; i++)
	{
		gets(s);
		length = strlen(s);
		word_first=0;
		word_last = 0;
		for(l=0; l<=length; l++)
		{
			if(s[l]==' ' || l==length)
			{
				e = word_first;
				for(word_last = l-1; e < word_last; word_first++)
				{
					st[e] = s[word_first];
					s[word_first] = s[word_last];
					s[word_last] = st[e];
					word_last--;
					e = word_first;
				}
				word_first = l+1;
			}
		}
		puts(s);
	}
	
	return 0;
}