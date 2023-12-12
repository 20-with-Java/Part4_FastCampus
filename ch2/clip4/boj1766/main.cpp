#include <iostream>
#include <queue>
#include <vector>

std::vector<int> nextOrder[32001];
int count[32001];
std::priority_queue<int, std::vector<int>, std::greater<int>> solvableProblem;

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    for(int i = 0; i < M; i++)
    {
        int A, B;
        scanf("%d %d", &A, &B);
        nextOrder[A].push_back(B);
        count[B]++;
    }

    for(int i = 1; i <= N; i++)
    {
        if(0 == count[i])
        {
            solvableProblem.push(i);
        }
    }

    while(solvableProblem.empty() == false)
    {
        int problemNumber = solvableProblem.top();
        solvableProblem.pop();
        printf("%d ", problemNumber);

        for(int num : nextOrder[problemNumber])
        {
            count[num]--;
            if(0 == count[num])
            {
                solvableProblem.push(num);
            }
        }
    }

    return 0;
}