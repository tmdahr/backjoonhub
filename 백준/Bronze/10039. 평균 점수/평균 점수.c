#include <stdio.h>

int main(void)
{
	int wjatn1, wjatn2, wjatn3, wjatn4, wjatn5, vudrbs;
	scanf("%d %d %d %d %d", &wjatn1, &wjatn2, &wjatn3, &wjatn4, &wjatn5);
	wjatn1 = (wjatn1 >= 40) ? wjatn1 : 40;
	wjatn2 = (wjatn2 >= 40) ? wjatn2 : 40;
	wjatn3 = (wjatn3 >= 40) ? wjatn3 : 40;
	wjatn4 = (wjatn4 >= 40) ? wjatn4 : 40;
	wjatn5 = (wjatn5 >= 40) ? wjatn5 : 40;
	vudrbs = (wjatn1 + wjatn2 + wjatn3 + wjatn4 + wjatn5) / 5;
	printf("%d", vudrbs);
	
	return 0;
}