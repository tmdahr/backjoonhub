#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    scanf("%d", &N);

    char morning[155], evening[155];
    scanf("%s", morning);
    scanf("%s", evening);

    int cntA = 0, cntB = 0;

    for(int i=0; i<N; i++) {
        if(morning[i] == 'w') cntA++;
        if(evening[i] == 'w') cntB++;
    }

    if(cntB < cntA) printf("Oryang\n");
    else if (cntB > cntA) printf("Manners maketh man\n");
    else {
        if(strcmp(morning, evening) == 0) printf("Good\n");
        else printf("Its fine\n");
    }

    return 0;
}