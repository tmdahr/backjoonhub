#include <stdio.h>

int isLeap(int y) {return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);}

int main(void) {
    int d, m, y;

    while(1) {
        scanf("%d %d %d", &d, &m, &y);

        if(d == 0 && m == 0 && y == 0) break;

        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        
        if(isLeap(y)) days[1] = 29;
        
        int sum = d;

        for(int i=0; i<m-1; i++) sum += days[i];

        printf("%d\n", sum);
    }

    return 0;
}