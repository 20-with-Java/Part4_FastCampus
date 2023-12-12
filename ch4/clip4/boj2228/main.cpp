#include <iostream>

#define MIN_VALUE (-10000000)

int main()
{
    int N, M;
    int num[101];
    int sum[51][101], maxValue[51][101];

    scanf("%d %d", &N, &M);

    sum[1][0] = MIN_VALUE;
    maxValue[1][0] = MIN_VALUE;
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &num[i]);
        sum[1][i] = std::max(sum[1][i - 1], 0) + num[i];
        maxValue[1][i] = std::max(maxValue[1][i - 1], sum[1][i]);
    }

    for(int j = 2; j <= M; j++)
    {
        for(int i = 0; i <= N; i++)
        {
            sum[j][i] = maxValue[j][i] = MIN_VALUE;
        }
    }

    for(int j = 2; j <= M; j++)
    {
        for(int i = j * 2 - 1; i <= N; i++)
        {
            sum[j][i] = std::max(sum[j][i - 1], maxValue[j - 1][i - 2]) + num[i];
            maxValue[j][i] = std::max(maxValue[j][i - 1], sum[j][i]);
        }
    }

    printf("%d", maxValue[M][N]);

    return 0;
}