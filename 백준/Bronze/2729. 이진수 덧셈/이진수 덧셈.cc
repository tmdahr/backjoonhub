#include <stdio.h>
#include <string.h>

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        char A[82], B[82];
        scanf("%s %s", A, B);

        int i = strlen(A) - 1;
        int j = strlen(B) - 1;

        char result[200];
        int idx = 0;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if(i >= 0) sum += A[i--] - '0';
            if(j >= 0) sum += B[j--] - '0';

            result[idx++] = (sum % 2) + '0';
            carry = sum / 2;
        }

        int start = idx - 1;
        while(start > 0 && result[start] == '0') start--;

        for(int k=start; k>=0; k--) printf("%c", result[k]);
        printf("\n");
    }
    return 0;
}