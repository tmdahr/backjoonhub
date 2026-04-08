#include <stdio.h>

int main(void) {
    int arr[3];

    for(int i=0; i<3; i++) scanf("%d", &arr[i]);
    
    for(int i=0; i<3; i++)
        for(int j=i+1; j<3; j++)
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    printf("%d %d %d\n", arr[0], arr[1], arr[2]);

    return 0;
}