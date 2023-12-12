#include <iostream>

int main()
{
    int n, m, board;
    int maxSize[1001][1001];
    int result = 0;

    scanf("%d %d", &n, &m);

    for(int j = 0; j <= n; j++)
    {
        maxSize[j][0] = 0;
    }

    for(int i = 0; i <= m; i++)
    {
        maxSize[0][i] = 0;
    }

    for(int j = 1; j <= n; j++)
    {
        for(int i = 1; i <= m; i++)
        {
            scanf("%1d", &board);
            if(1 == board)
            {
                maxSize[j][i] = maxSize[j - 1][i - 1];
                if(maxSize[j][i] > std::min(maxSize[j - 1][i], maxSize[j][i - 1]))
                {
                    maxSize[j][i] = std::min(maxSize[j - 1][i], maxSize[j][i - 1]);
                }
                maxSize[j][i]++;

                if(maxSize[j][i] > result)
                {
                    result = maxSize[j][i];
                }
            }
            else
            {
                maxSize[j][i] = 0;
            }
        }
    }

    printf("%d", result * result);

    return 0;
}