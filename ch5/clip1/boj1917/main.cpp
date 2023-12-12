#include <iostream>

int data[6][6];
bool isVisited[6][6];
bool usedSide[6];

struct point_t
{
    int r;
    int c;
    point_t operator+(point_t rhs)
    {
        return {r + rhs.r, c + rhs.c};
    }
} direction[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

// 0
// 1 2 3 4
// 5
int cube[6] = {0, 1, 2, 3, 4, 5};

void rollUp()
{
    int temp = cube[0];
    cube[0] = cube[1];
    cube[1] = cube[5];
    cube[5] = cube[3];
    cube[3] = temp;

    return;
}

void rollDown()
{
    int temp = cube[0];
    cube[0] = cube[3];
    cube[3] = cube[5];
    cube[5] = cube[1];
    cube[1] = temp;

    return;
}

void rollLeft()
{
    int temp = cube[0];
    cube[0] = cube[2];
    cube[2] = cube[5];
    cube[5] = cube[4];
    cube[4] = temp;

    return;
}

void rollRight()
{
    int temp = cube[0];
    cube[0] = cube[4];
    cube[4] = cube[5];
    cube[5] = cube[2];
    cube[2] = temp;

    return;
}

void (*roll[4])(void) = {rollUp, rollLeft, rollDown, rollRight};

bool isCube(point_t now)
{
    isVisited[now.r][now.c] = true;
    if(true == usedSide[cube[0]])
    {
        return false;
    }

    usedSide[cube[0]] = true;

    for(int i = 0; i < 4; i++)
    {
        point_t next = now + direction[i];

        if(next.r < 0 || next.r >= 6 || next.c < 0 || next.c >= 6
        || true == isVisited[next.r][next.c])
        {
            continue;
        }

        roll[i]();
        if(isCube(next) == false)
        {
            return false;
        }
        roll[(i + 2) % 4]();
    }

    return true;
}

int main()
{
    for(int t = 0; t < 3; t++)
    {
        for(int r = 0; r < 6; r++)
        {
            for(int c = 0; c < 6; c++)
            {
                scanf("%d", &data[r][c]);
                if(0 == data[r][c])
                {
                    isVisited[r][c] = true;
                }
                else
                {
                    isVisited[r][c] = false;
                }
            }
        }

        for(int i = 0; i < 6; i++)
        {
            cube[i] = i;
            usedSide[i] = false;
        }

        for(int i = 0; i < 36; i++)
        {
            if(1 == data[i / 6][i % 6])
            {
                if(isCube({i / 6, i % 6}) == true)
                {
                    printf("yes\n");
                }
                else
                {
                    printf("no\n");
                }
                break;
            }
        }
    }

    return 0;
}