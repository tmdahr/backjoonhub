#include <stdio.h>

int main(void) {
    char g[3];
    scanf("%s", g);

    double base;

    switch(g[0]) {
        case 'A': base = 4.0; break;
        case 'B': base = 3.0; break;
        case 'C': base = 2.0; break;
        case 'D': base = 1.0; break;
        default: printf("0.0\n"); return 0;
    }

    if(g[1] == '+') base += 0.3;
    else if(g[1] == '-') base -= 0.3;

    printf("%.1f\n", base);

    return 0;
}