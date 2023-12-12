#include <iostream>
#include <queue>

struct point_t
{
    int y;
    int x;
    int wall = 0;
    point_t operator+(point_t rhs)
    {
        return {y + rhs.y, x + rhs.x, wall + rhs.wall};
    }
    bool operator()(point_t a, point_t b)
    {
        return a.wall > b.wall;
    }
};

point_t direction[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main()
{
    int N, M;
    int maze[101][101];
    int minimumWall[101][101];

    scanf("%d %d", &M, &N);
    for(int j = 1; j <= N; j++)
    {
        for(int i = 1; i <= M; i++)
        {
            scanf("%1d", &maze[j][i]);
            minimumWall[j][i] = 10001;
        }
    }

    std::priority_queue<point_t, std::vector<point_t>, point_t> pq;

    pq.push({1, 1, 0});
    minimumWall[1][1] = 0;

    for(;;)
    {
        point_t now = pq.top();
        point_t next;

        pq.pop();

        if(now.x == M && now.y == N)
        {
            printf("%d", minimumWall[N][M]);
            break;
        }
        
        for(int i = 0; i < 4; i++)
        {
            next = now + direction[i];
            next.wall += maze[next.y][next.x];

            if(next.x >= 1 && next.x <= M && next.y >= 1 && next.y <= N)
            {
                if(minimumWall[next.y][next.x] > next.wall)
                {
                    minimumWall[next.y][next.x] = next.wall;
                    pq.push(next);
                }
            }
        }
    }

    return 0;
}