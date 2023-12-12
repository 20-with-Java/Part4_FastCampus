#include <iostream>

#define MAX_VALUE (0x7FFFFFFF)

struct data_t
{
    int minCost;
    int divIndex;    
} dp[501][501];
int sumCost[501];

int main()
{
    int T, K;
    scanf("%d", &T);

    for(int t = 0; t < T; t++)
    {
        int cost;
        scanf("%d", &K);
        sumCost[0] = 0;
        for(int i = 1; i <= K; i++)
        {
            scanf("%d", &cost);
            sumCost[i] = sumCost[i - 1] + cost;
        }

        for(int i = 1; i <= K; i++)
        {
            dp[i][i] = {0, i};
        }

        for(int length = 2; length <= K; length++)
        {
            for(int begin = 1; begin <= K - length + 1; begin++)
            {
                int end = begin + length - 1;
                dp[begin][end].minCost = MAX_VALUE;
                for(int i = dp[begin][end - 1].divIndex; i <= dp[begin + 1][end].divIndex; i++)
                {
                    if(dp[begin][end].minCost > dp[begin][i].minCost + dp[i + 1][end].minCost + sumCost[end] - sumCost[begin - 1])
                    {
                        dp[begin][end] = {dp[begin][i].minCost + dp[i + 1][end].minCost + sumCost[end] - sumCost[begin - 1], i};
                    }
                }
            }
        }

        printf("%d\n", dp[1][K]);
    }

    return 0;
}