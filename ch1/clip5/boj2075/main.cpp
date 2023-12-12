#include <iostream>
#include <queue>

int main()
{
    int N, num;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        pq.push(num);
    }

    for(int j = 1; j < N; j++)
    {
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &num);
            pq.push(num);
            pq.pop();
        }
    }

    printf("%d", pq.top());

    return 0;
}