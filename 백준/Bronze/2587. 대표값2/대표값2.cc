#include <stdio.h>

int main(void) {
    int arr[5];
    int sum = 0;

    for(int i=0; i<5; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    for(int i=0; i<4; i++) {
        for(int j=i+1; j<5; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("%d\n", sum / 5);
    printf("%d\n", arr[2]);

    return 0;
}