#include <iostream>

#define MAX_VALUE (0x7FFFFFFF)
#define POW(A) ((A) * (A))

int H, W;
int image[2][101][101];
int dp[102][102];

int func(int r, int c)
{
    if(dp[r][c] != -1)
    {
        return dp[r][c];
    }

    dp[r][c] = func(r - 1, c - 1);
    if(dp[r][c] > std::min(func(r - 1, c), func(r - 1, c + 1)))
    {
        dp[r][c] = std::min(dp[r - 1][c], dp[r - 1][c + 1]);
    }
    dp[r][c] += POW(image[0][r][c] - image[1][r][c]);

    return dp[r][c];
}

int main()
{
    scanf("%d %d", &H, &W);

    for(int i = 0; i <= 1; i++)
    {
        for(int r = 1; r <= H; r++)
        {
            for(int c = 1; c <= W; c++)
            {
                scanf("%d", &image[i][r][c]);
            }
        }
    }

    for(int r = 1; r <= H; r++)
    {
        for(int c = 1; c <= W; c++)
        {
            dp[r][c] = -1;
        }
    }

    for(int c = 0; c <= W; c++)
    {
        dp[0][c] = 0;
    }

    for(int r = 0; r <= H; r++)
    {
        dp[r][0] = dp[r][W + 1] = MAX_VALUE;
    }

    int result = MAX_VALUE;

    for(int c = 1; c <= W; c++)
    {
        if(func(H, c) < result)
        {
            result = func(H, c);
        }
    }

    printf("%d", result);

    return 0;
}