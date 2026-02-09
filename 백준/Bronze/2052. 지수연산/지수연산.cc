#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int num[2000] = {0};
    int len = 1;
    num[0] = 1;

    for(int i=0; i<N; i++) {
        int carry = 0;
        for(int j=0; j<len; j++) {
            int v = num[j] * 5 + carry;
            num[j] = v % 10;
            carry = v / 10;
        }
        while(carry) {
            num[len++] = carry % 10;
            carry /= 10;
        }
    }

    printf("0.");
    for(int i=0; i<N-len; i++) printf("0");
    for(int i=len-1; i>=0; i--) printf("%d", num[i]);
    printf("\n");
    return 0;
}