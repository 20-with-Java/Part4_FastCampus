#include <iostream>
#include <vector>

int D[1001];
int maximumTime[1001];
std::vector<int> frontOrder[1001];

int get_time(int buildingNumber)
{
    if(maximumTime[buildingNumber] != -1)
    {
        return maximumTime[buildingNumber];
    }

    maximumTime[buildingNumber] = 0;

    for(int frontNumber : frontOrder[buildingNumber])
    {
        int frontTime = get_time(frontNumber);
        if(frontTime > maximumTime[buildingNumber])
        {
            maximumTime[buildingNumber] = frontTime;
        }
    }

    maximumTime[buildingNumber] += D[buildingNumber];

    return maximumTime[buildingNumber];
}

int main()
{
    int T;
    scanf("%d" ,&T);
    for(int t = 0; t < T; t++)
    {
        int N, K, X, Y, W;
        scanf("%d %d", &N, &K);

        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &D[i]);
            frontOrder[i].clear();
            maximumTime[i] = -1;
        }

        for(int i = 0; i < K; i++)
        {
            scanf("%d %d", &X, &Y);
            frontOrder[Y].push_back(X);
        }

        scanf("%d", &W);

        printf("%d\n", get_time(W));
    }
    return 0;
}