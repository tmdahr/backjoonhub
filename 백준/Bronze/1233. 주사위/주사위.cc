#include <stdio.h>

int main(void) {
    int S1, S2, S3;
    int count[81] = {0};
    scanf("%d %d %d", &S1, &S2, &S3);

    for(int i=1; i<=S1; i++)
        for(int j=1; j<=S2; j++)
            for(int k=1; k<=S3; k++) {
                int sum = i+j+k;
                count[sum]++;
            }

    int maxCount = 0;
    int answer = 0;

    for(int s=3; s <= S1+S2+S3; s++)
        if(count[s] > maxCount) {
            maxCount = count[s];
            answer = s;
        }

    printf("%d\n", answer);
    return 0;
}