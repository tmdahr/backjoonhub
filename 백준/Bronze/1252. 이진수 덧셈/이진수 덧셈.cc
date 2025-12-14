#include <stdio.h>
#include <string.h>

int main(void) {
    char A[100005], B[100005];
    char result[100010];

    scanf("%s %s", A, B);

    int i = strlen(A) - 1;
    int j = strlen(B) - 1;
    int k = 0;
    int carry = 0;

    while(i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if(i >= 0) sum += A[i--] - '0';
        if(j >= 0) sum += B[j--] - '0';

        result[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }

    int idx = k-1;
    while(idx > 0 && result[idx] == '0') idx--;

    for(int p=idx; p>=0; p--) putchar(result[p]);

    return 0;
}
