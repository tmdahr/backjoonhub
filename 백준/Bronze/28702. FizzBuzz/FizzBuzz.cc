#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char arr[3][9];
    int n;
    for (int i=0; i<3; i++) {
        scanf("%s", arr[i]);
        if ((strcmp(arr[i],"Fizz")!=0) && (strcmp(arr[i],"Buzz")!=0) && (strcmp(arr[i],"FizzBuzz")!=0))
            n = atoi(arr[i])+3-i;
    }
    if (n%15==0)
        printf("FizzBuzz");
    else if (n%3==0)
        printf("Fizz");
    else if (n%5==0)
        printf("Buzz");
    else
        printf("%d", n);
	return 0;    
}