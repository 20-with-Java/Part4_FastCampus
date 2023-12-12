#include <iostream>
#include <vector>
#include <queue>

struct edge_t
{
    int nodeNumber;
    long long cost;
    int k;
    bool operator()(edge_t a, edge_t b)
    {
        return a.cost > b.cost;
    }
};

int N, M, K;
std::vector<edge_t> edge[10001];
std::priority_queue<edge_t, std::vector<edge_t>, edge_t> pq;
long long minimumCost[21][10001];

int main()
{
    scanf("%d %d %d", &N, &M, &K);

    for(int j = 0; j <= K; j++)
    {
        for(int i = 1; i <= N; i++)
        {
            minimumCost[j][i] = 0x7FFFFFFFFFFFFFFF - 1000000;
        }
    }

    for(int i = 0; i < M; i++)
    {
        int u, v;
        long long cost;
        scanf("%d %d %lld", &u, &v, &cost);

        edge[u].push_back({v, cost});
        edge[v].push_back({u, cost});
    }

    minimumCost[0][1] = 0;
    pq.push({1, 0});

    for(;;)
    {
        int nowNode = pq.top().nodeNumber, nowCost = pq.top().cost, nowK = pq.top().k;
        
        if(nowNode == N)
        {
            printf("%lld\n", minimumCost[nowK][nowNode]);
            break;
        }

        pq.pop();

        if(minimumCost[nowK][nowNode] < nowCost)
        {
            continue;
        }

        for(edge_t e : edge[nowNode])
        {
            if(minimumCost[nowK][e.nodeNumber] > minimumCost[nowK][nowNode] + e.cost)
            {
                minimumCost[nowK][e.nodeNumber] = minimumCost[nowK][nowNode] + e.cost;
                pq.push({e.nodeNumber, minimumCost[nowK][e.nodeNumber], nowK});
            }

            if(nowK < K)
            {
                if(minimumCost[nowK + 1][e.nodeNumber] > minimumCost[nowK][nowNode])
                {
                    minimumCost[nowK + 1][e.nodeNumber] = minimumCost[nowK][nowNode];
                    pq.push({e.nodeNumber, minimumCost[nowK + 1][e.nodeNumber], nowK + 1});
                }
            }
        }
    }

    return 0;
}