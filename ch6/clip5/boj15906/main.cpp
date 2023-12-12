#include <iostream>
#include <queue>

#define MAX_VALUE (1000)

struct point_t
{
    int r;
    int c;
    int changed;
    int cost;
    point_t operator+(point_t rhs)
    {
        return {r + rhs.r, c + rhs.c, changed + rhs.changed, cost + rhs.cost};
    }
    bool operator()(point_t a, point_t b)
    {
        return a.cost > b.cost;
    }
};

point_t direction[4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {-1, 0, 0, 0}, {0, -1, 0, 0}};

char board[501][501];
int cost[2][501][501];
int main()
{
    int N, t;
    point_t goal;
    scanf("%d %d %d %d", &N, &t, &goal.r, &goal.c);

    for(int r = 1; r <= N; r++)
    {
        for(int c = 1; c <= N; c++)
        {
            scanf(" %c", &board[r][c]);
            cost[0][r][c] = cost[1][r][c] = MAX_VALUE;
        }
    }

    std::priority_queue<point_t, std::vector<point_t>, point_t> pq;

    for(pq.push({1, 1, 0, 0}); ;)
    {
        point_t now = pq.top();
        pq.pop();

        if(now.r == goal.r && now.c == goal.c)
        {
            printf("%d", now.cost);
            break;
        }

        if(cost[now.changed][now.r][now.c] < now.cost)
        {
            continue;
        }

        for(int i = 0; i < 4; i++)
        {
            point_t next = now + direction[i];
            if(next.r <= 0 || next.r > N || next.c <= 0 || next.c > N)
            {
                continue;
            }

            next.changed = 0;
            next.cost = now.cost + 1;

            if(cost[0][next.r][next.c] > next.cost)
            {
                cost[0][next.r][next.c] = next.cost;
                pq.push(next);
            }
        }

        for(int i = 0; i < 4; i++)
        {
            point_t next = now + direction[i];
            if(0 == next.changed)
            {
                next.changed = 1;
                next.cost = now.cost + t;
            }
            next.cost = next.cost + 1;

            for(; ; next = next + direction[i])
            {
                if(next.r <= 0 || next.r > N || next.c <= 0 || next.c > N)
                {
                    break;
                }

                if('#' == board[next.r][next.c])
                {
                    if(cost[1][next.r][next.c] > next.cost)
                    {
                        cost[1][next.r][next.c] = next.cost;
                        pq.push(next);
                    }
                    break;
                }
            }
        }
    }


    return 0;
}