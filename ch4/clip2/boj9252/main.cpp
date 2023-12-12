#include <iostream>

int dp[1002][1002];
char str[2][1002];

void print_LCS(int j, int i)
{
    if(j <= 0 || i <= 0)
    {
        return;
    }

    if(dp[j][i] == dp[j - 1][i])
    {
        print_LCS(j - 1, i);
    }
    else if(dp[j][i] == dp[j][i - 1])
    {
        print_LCS(j, i - 1);
    }
    else
    {
        print_LCS(j - 1, i - 1);
        printf("%c", str[0][j]);
    }

    return;
}

int main()
{
    
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

    printf("%d\n", dp[j - 1][i - 1]);
    print_LCS(j - 1, i - 1);

    return 0;
}