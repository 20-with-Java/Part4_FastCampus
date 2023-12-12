#include <iostream>
#include <queue>

int main()
{
    int N, M, number;
    std::queue<int> q;

    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    int result = 0;
    for(int i = 0; i < M; i++)
    {
        scanf("%d", &number);

        int count = 0;
        while(q.front() != number)
        {
            q.push(q.front());
            q.pop();
            count++;
        }

        if(count > q.size() - count)
        {
            count = q.size() - count;
        }
        q.pop();

        result += count;
    }

    printf("%d", result);

    return 0;
}