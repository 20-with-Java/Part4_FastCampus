#include <iostream>

int number[2001];
int isPalindrome[2001][2001];

int func(int beginIndex, int endIndex)
{
    if(beginIndex >= endIndex)
    {
        return 1;
    }

    if(isPalindrome[beginIndex][endIndex] != -1)
    {
        return isPalindrome[beginIndex][endIndex];
    }

    if(number[beginIndex] != number[endIndex])
    {
        isPalindrome[beginIndex][endIndex] = 0;
    }
    else
    {
        isPalindrome[beginIndex][endIndex] = func(beginIndex + 1, endIndex - 1);
    }

    return isPalindrome[beginIndex][endIndex];
}

int main()
{
    int N, M , S, E;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &number[i]);
    }

    for(int j = 1; j <= N; j++)
    {
        for(int i = 1; i <= N; i++)
        {
            isPalindrome[j][i] = -1;
        }
    }

    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d", &S, &E);

        printf("%d\n", func(S, E));
    }

    return 0;
}