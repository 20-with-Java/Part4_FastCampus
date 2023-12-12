#include <iostream>
#include <vector>

std::vector<int> frontOrder[1001];
bool visited[1001];
int dfsDepth[1001];
std::vector<int> result;

bool dfs(int singerNumber, int depth)
{
    visited[singerNumber] = true;
    dfsDepth[singerNumber] = depth;

    for(int frontNumber : frontOrder[singerNumber])
    {
        if(false == visited[frontNumber])
        {
            if(dfs(frontNumber, depth + 1) == false)
            {
                return false;
            }
        }
        else
        {
            if(dfsDepth[singerNumber] > dfsDepth[frontNumber])
            {
                return false;
            }
        }
    }

    dfsDepth[singerNumber] = 1001;

    result.push_back(singerNumber);

    return true;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    for(int j = 0; j < M; j++)
    {
        int count = 0, prev = 0, next;

        scanf("%d", &count);
        
        for(int i = 0; i < count; i++)
        {
            scanf("%d", &next);
            frontOrder[next].push_back(prev);
            prev = next;
        }
    }

    visited[0] = true;
    dfsDepth[0] = 1001;
    for(int i = 1; i <= N; i++)
    {
        if(false == visited[i])
        {
            if(dfs(i, 1) == false)
            {
                printf("0");
                return 0;
            }
        }
    }

    for(int res : result)
    {
        printf("%d\n", res);
    }

    return 0;
}