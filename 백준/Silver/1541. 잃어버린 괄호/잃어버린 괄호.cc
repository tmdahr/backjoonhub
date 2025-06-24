#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[51];
	int arr[25] = {0};
	scanf("%s", str);
	int len = strlen(str);
	int j = 0, sum = 0, temp=0;
	for(int i=0; i<=len; i++)
	{
		if(str[i] == '-' || i == len)
		{
			sum = sum + temp;
			arr[j] = sum;
			j++;
			temp = 0;
			sum = 0;
		}
		else if(str[i] == '+')
		{
			sum = sum + temp;
			temp = 0;
		}
		else
		{
			temp = temp * 10;
			temp = temp + str[i] - '0';
		}
	}
	int result = arr[0];
	for(int i = 1; i < j; i++) result = result - arr[i];
	printf("%d", result);
    
    return 0;
}