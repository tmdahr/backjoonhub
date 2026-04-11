#include <stdio.h>
#include <string.h>
#include <math.h>

double getScore(char *g) {
    if (strcmp(g, "A+") == 0) return 4.3;
    if (strcmp(g, "A0") == 0) return 4.0;
    if (strcmp(g, "A-") == 0) return 3.7;
    if (strcmp(g, "B+") == 0) return 3.3;
    if (strcmp(g, "B0") == 0) return 3.0;
    if (strcmp(g, "B-") == 0) return 2.7;
    if (strcmp(g, "C+") == 0) return 2.3;
    if (strcmp(g, "C0") == 0) return 2.0;
    if (strcmp(g, "C-") == 0) return 1.7;
    if (strcmp(g, "D+") == 0) return 1.3;
    if (strcmp(g, "D0") == 0) return 1.0;
    if (strcmp(g, "D-") == 0) return 0.7;
    return 0.0; 
}

int main() {
    int N;
    scanf("%d", &N);

    int creditSum = 0;
    double total = 0;

    while (N--) {
        char subject[50];
        int credit;
        char grade[3];

        scanf("%s %d %s", subject, &credit, grade);

        double score = getScore(grade);

        creditSum += credit;
        total += credit * score;
    }

    double result = total / creditSum;

    result = round(result * 100) / 100;

    printf("%.2f\n", result);

    return 0;
}