#include <stdio.h>

int main(void) {

    char eight[333335];
    char two[8][4] = {
        "000", "001", "010", "011",
        "100", "101", "110", "111"
    };
    scanf("%s", eight);

    int first = eight[0] - '0';
    if(first == 0) printf("0");
    else if(first == 1) printf("1");
    else if(first == 2) printf("10");
    else if(first == 3) printf("11");
    else if(first == 4) printf("100");
    else if(first == 5) printf("101");
    else if(first == 6) printf("110");
    else if(first == 7) printf("111");

    for(int i = 1; eight[i] != '\0'; i++)
        printf("%s", two[eight[i] - '0']);

    return 0;
}
