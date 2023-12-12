#include <iostream>

int dp[1002][1002];

int main()
{
    char str[2][1002];
    
    scanf("%s %s", &str[0][1], &str[1][1]);

    int j, i;
    for(j = 1; str[0][j] != '\0'; j++)
    {
        for(i = 1; str[1][i] != '\0'; i++)
        {
            if(str[0][j] == str[1][i])
            {
                dp[j][i] = dp[j - 1][i - 1] + 1;
            }
            else
            {
                dp[j][i] = std::max(dp[j - 1][i], dp[j][i - 1]);
            }
        }
    }

    printf("%d", dp[j - 1][i - 1]);

    return 0;
}