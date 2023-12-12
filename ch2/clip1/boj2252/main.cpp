#include <iostream>
#include <vector>

std::vector<int> frontOrder[32001];
bool visited[32001];

void dfs(int studentNumber)
{
    visited[studentNumber] = true;

    for(int frontNumber : frontOrder[studentNumber])
    {
        if(false == visited[frontNumber])
        {
            dfs(frontNumber);
        }
    }
    printf("%d ", studentNumber);
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    for(int i = 0; i < M; i++)
    {
        int A, B;
        scanf("%d %d", &A, &B);
        frontOrder[B].push_back(A);
    }

    for(int i = 1; i <= N; i++)
    {
        if(false == visited[i])
        {
            dfs(i);
        }
    }

    return 0;
}