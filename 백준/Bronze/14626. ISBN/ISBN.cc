#include <stdio.h>
#include <string.h>

int main() {
    char isbn[14]; // 13자리 + NULL
    scanf("%s", isbn);

    int sum = 0;
    int x_index = -1;

    for (int i = 0; i < 13; i++) {
        if (isbn[i] == '*') {
            x_index = i;
            continue;
        }

        int num = isbn[i] - '0';

        if ((i + 1) % 2 == 1)  // 홀수 위치
            sum += num;
        else  // 짝수 위치
            sum += num * 3;
    }

    for (int x = 0; x <= 9; x++) {
        int total = sum;

        if ((x_index + 1) % 2 == 1)
            total += x;
        else
            total += x * 3;

        if (total % 10 == 0) {
            printf("%d\n", x);
            break;
        }
    }

    return 0;
}
