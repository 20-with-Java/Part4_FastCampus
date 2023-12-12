#include <iostream>
#include <queue>
#include <vector>

struct edge_t
{
    int nodeNumber;
    int cost;

    bool operator()(edge_t a, edge_t b)
    {
        return a.cost > b.cost;
    }
};

std::vector<edge_t> edge[1001], reverseEdge[1001];

int main()
{
    int N, M, X;
    scanf("%d %d %d", &N, &M, &X);

    for(int i = 0; i < M; i++)
    {
        int A, B, cost;
        scanf("%d %d %d", &A, &B, &cost);
        edge[A].push_back({B, cost});
        reverseEdge[B].push_back({A, cost});
    }

    std::priority_queue<edge_t, std::vector<edge_t>, edge_t> pq;
    int minimumCost[2][1001];
    for(int i = 1; i <= N; i++)
    {
        minimumCost[0][i] = 100001;
    }

    minimumCost[0][X] = 0;

    pq.push({X, 0});

    while(pq.empty() == false)
    {
        edge_t now = pq.top();
        pq.pop();

        if(minimumCost[0][now.nodeNumber] > now.cost)
        {
            continue;
        }

        for(edge_t nextEdge : edge[now.nodeNumber])
        {
            if(minimumCost[0][nextEdge.nodeNumber] > now.cost + nextEdge.cost)
            {
                minimumCost[0][nextEdge.nodeNumber] = now.cost + nextEdge.cost;
                pq.push({nextEdge.nodeNumber, now.cost + nextEdge.cost});
            }
        }
    }

    for(int i = 1; i <= N; i++)
    {
        minimumCost[1][i] = 100001;
    }

    minimumCost[1][X] = 0;

    pq.push({X, 0});

    while(pq.empty() == false)
    {
        edge_t now = pq.top();
        pq.pop();

        if(minimumCost[1][now.nodeNumber] > now.cost)
        {
            continue;
        }

        for(edge_t nextEdge : reverseEdge[now.nodeNumber])
        {
            if(minimumCost[1][nextEdge.nodeNumber] > now.cost + nextEdge.cost)
            {
                minimumCost[1][nextEdge.nodeNumber] = now.cost + nextEdge.cost;
                pq.push({nextEdge.nodeNumber, now.cost + nextEdge.cost});
            }
        }
    }

    int result = 0;
    for(int i = 1; i <= N; i++)
    {
        if(result < minimumCost[0][i] + minimumCost[1][i])
        {
            result = minimumCost[0][i] + minimumCost[1][i];
        }
    }

    printf("%d", result);

    return 0;
}