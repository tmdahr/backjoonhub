#include<stdio.h>
 
long int tri[101] = { 0,1,1,1,2,2 };    // tri[5]까지 초기화
 
int main() {
    int T, N, t, i;
    scanf("%d", &T);
    for (t = 0; t < T; t++) {
        scanf("%d", &N);
        for (i = 6; i <= N; i++)
            tri[i] = tri[i - 5] + tri[i - 1];
        printf("%ld\n", tri[N]);
    }
	return 0;
}