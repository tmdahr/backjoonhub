#include <stdio.h>

int max(int a, int b) {return a > b ? a : b;}
int min(int a, int b) {return a < b ? a : b;}

int main(void)
{
    int N;
    scanf("%d", &N);
    int a, b, c;
    int max_dp[3], min_dp[3], tmp_max[3], tmp_min[3];

    scanf("%d %d %d", &a, &b, &c);
    max_dp[0] = min_dp[0] = a;
    max_dp[1] = min_dp[1] = b;
    max_dp[2] = min_dp[2] = c;

    for(int i=1; i<N; i++)
    {
        scanf("%d %d %d", &a, &b, &c);

        tmp_max[0] = max(max_dp[0], max_dp[1]) + a;
        tmp_max[1] = max(max(max_dp[0], max_dp[1]), max_dp[2]) + b;
        tmp_max[2] = max(max_dp[1], max_dp[2]) + c;

        tmp_min[0] = min(min_dp[0], min_dp[1]) + a;
        tmp_min[1] = min(min(min_dp[0], min_dp[1]), min_dp[2]) + b;
        tmp_min[2] = min(min_dp[1], min_dp[2]) + c;

        for(int j=0; j<3; j++)
        {
            max_dp[j] = tmp_max[j];
            min_dp[j] = tmp_min[j];
        }
    }

    int max_ans = max(max_dp[0], max(max_dp[1], max_dp[2]));
    int min_ans = min(min_dp[0], min(min_dp[1], min_dp[2]));
    printf("%d %d\n", max_ans, min_ans);

    return 0;
}