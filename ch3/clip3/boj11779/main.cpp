#include <iostream>
#include <vector>
#include <queue>

struct edge_t
{
    int nodeNumber;
    int cost;
    bool operator()(edge_t a, edge_t b)
    {
        return a.cost > b.cost;
    }
};

int N, M;
std::vector<edge_t> edge[1001];
std::priority_queue<edge_t, std::vector<edge_t>, edge_t> pq;
int minimumCost[1001];
int prevNode[1001];

void printRoute(int nodeNumber, int countCity)
{
    if(0 == nodeNumber)
    {
        printf("%d\n", countCity);
    }
    else
    {
        printRoute(prevNode[nodeNumber], countCity + 1);
        printf("%d ", nodeNumber);
    }

    return;
}

int main()
{
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++)
    {
        minimumCost[i] = 100000000;
    }

    for(int i = 0; i < M; i++)
    {
        int u, v, cost;
        scanf("%d %d %d", &u, &v, &cost);

        edge[u].push_back({v, cost});
    }

    int startNumber, finishNumber;
    scanf("%d %d", &startNumber, &finishNumber);

    prevNode[startNumber] = 0;
    minimumCost[startNumber] = 0;
    pq.push({startNumber, 0});

    for(;;)
    {
        int nowNode = pq.top().nodeNumber, nowCost = pq.top().cost;
        
        if(nowNode == finishNumber)
        {
            printf("%d\n", minimumCost[nowNode]);
            printRoute(nowNode, 0);
            break;
        }

        pq.pop();

        if(minimumCost[nowNode] < nowCost)
        {
            continue;
        }

        for(edge_t e : edge[nowNode])
        {
            if(minimumCost[e.nodeNumber] > minimumCost[nowNode] + e.cost)
            {
                minimumCost[e.nodeNumber] = minimumCost[nowNode] + e.cost;
                prevNode[e.nodeNumber] = nowNode;
                pq.push({e.nodeNumber, minimumCost[e.nodeNumber]});
            }
        }
    }

    return 0;
}