#include <stdio.h>

int main(void) {
    int num;
    int max = -1;
    int row = 0, col = 0;

    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            scanf("%d", &num);

            if(num > max){
                max = num;
                row = i;
                col = j;
            }
        }
    }

    printf("%d\n", max);
    printf("%d %d\n", row, col);

    return 0;
}