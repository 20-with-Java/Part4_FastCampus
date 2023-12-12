#include <iostream>

int N, M;
int cardNumber[100000];
int usedNumberIndex[500001];

bool func(int size)
{
    int packCount = 0;
    int beginIndex = 0, endIndex = 0;

    for(int i = 1; i <= 500000; i++)
    {
        usedNumberIndex[i] = -1;
    }

    for(; endIndex < N; endIndex++)
    {
        if(usedNumberIndex[cardNumber[endIndex]] >= beginIndex)
        {
            beginIndex = usedNumberIndex[cardNumber[endIndex]] + 1;
        }

        usedNumberIndex[cardNumber[endIndex]] = endIndex;

        if(endIndex - beginIndex == size - 1)
        {
            packCount++;
            beginIndex = endIndex + 1;
        }

        if(packCount == M)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    scanf("%d %d", &N ,&M);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &cardNumber[i]);
    }

    int minSize = 1, maxSize = N / M;
    while(minSize < maxSize)
    {
        int findSize = (minSize + maxSize + 1) / 2;
    
        if(func(findSize) == true)
        {
            minSize = findSize;
        }
        else
        {
            maxSize = findSize - 1;
        }
    }

    printf("%d", maxSize);

    return 0;
}