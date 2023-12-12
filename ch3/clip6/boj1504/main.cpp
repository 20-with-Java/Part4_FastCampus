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

int N, E, V[2];
std::vector<edge_t> edge[801];

int func(int startNumber, int finishNumber)
{
    std::priority_queue<edge_t, std::vector<edge_t>, edge_t> pq;
    int minimumCost[801];

    for(int i = 1; i <= N; i++)
    {
        minimumCost[i] = 800001;
    }
    minimumCost[startNumber] = 0;

    pq.push({startNumber, 0});

    while(pq.empty() == false)
    {
        edge_t now = pq.top();
        pq.pop();

        if(minimumCost[now.nodeNumber] > now.cost)
        {
            continue;
        }

        if(now.nodeNumber == finishNumber)
        {
            return minimumCost[finishNumber];
        }

        for(edge_t nextEdge : edge[now.nodeNumber])
        {
            if(minimumCost[nextEdge.nodeNumber] > now.cost + nextEdge.cost)
            {
                minimumCost[nextEdge.nodeNumber] = now.cost + nextEdge.cost;
                pq.push({nextEdge.nodeNumber, now.cost + nextEdge.cost});
            }
        }
    }

    return -1;
}

int main()
{

    scanf("%d %d", &N, &E);

    for(int i = 0; i < E; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    scanf("%d %d", &V[0], &V[1]);

    int cost1ToV1 = func(1, V[0]);
    int costV2ToN = func(V[1], N);
    int cost1ToV2 = func(1, V[1]);
    int costV1ToN = func(V[0], N);
    int costV1ToV2 = func(V[0], V[1]);

    if(-1 == cost1ToV1 || -1 == costV2ToN || -1 == cost1ToV2 || -1 == costV1ToN || -1 == costV1ToV2)
    {
        printf("-1");
        return 0;
    }

    if(cost1ToV1 + costV2ToN < cost1ToV2 + costV1ToN)
    {
        printf("%d", cost1ToV1 + costV1ToV2 + costV2ToN);
    }
    else
    {
        printf("%d", cost1ToV2 + costV1ToV2 + costV1ToN);
    }

    return 0;
}