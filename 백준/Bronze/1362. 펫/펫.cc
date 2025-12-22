#include <stdio.h>

int main(void) {
    int O, W;
    int caseNum = 1;

    while(1) {
        scanf("%d %d", &O, &W);
        if(O == 0 && W == 0) break;

        int alive = 1;

        while(1) {
            char cmd;
            int x;
            scanf(" %c %d", &cmd, &x);

            if(cmd == '#' && x == 0) break;
            if(!alive) continue;

            if(cmd == 'E') W -= x;
            else if (cmd == 'F') W += x;

            if(W <= 0) alive = 0;
        }

        printf("%d ", caseNum++);

        if(!alive) printf("RIP\n");
        else if(W > O / 2 && W < O * 2) printf(":-)\n");
        else printf(":-(\n");
    }

    return 0;
}