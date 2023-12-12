#include <iostream>

#define POW(A) ((A) * (A))

int main()
{
    int N;
    int X[1001], Y[1001];
    int dp[1001][1001];

    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &X[i]);
    }

    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &Y[i]);
    }

    for(int i = 0; i <= N; i++)
    {
        dp[0][i] = dp[i][0] = 2000000000;
    }

    dp[0][0] = 0;

    for(int j = 1; j <= N; j++)
    {
        for(int i = 1; i <= N; i++)
        {
            int minValue = dp[j - 1][i - 1];
            if(minValue > std::min(dp[j - 1][i], dp[j][i - 1]))
            {
                minValue = std::min(dp[j - 1][i], dp[j][i - 1]);
            }

            dp[j][i] = minValue + POW(X[j] - Y[i]);
        }
    }

    printf("%d", dp[N][N]);

    return 0;
}