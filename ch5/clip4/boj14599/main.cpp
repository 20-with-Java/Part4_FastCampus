#include <iostream>
#include <queue>

int block[19][4][4] = {
{
    {1, 1, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 0},
    {0, 0, 0, 0}
},
{
    {1, 0, 0, 0},
    {1, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
},
{
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 0}
},
{
    {1, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
},

{
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 0}
},
{
    {1, 1, 1, 0},
    {1, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
},
{
    {1, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 0}
},
{
    {0, 0, 1, 0},
    {1, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
},

{
    {1, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 0}
},
{
    {1, 1, 1, 1},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
},

{
    {1, 1, 0, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
},

{
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {1, 0, 0, 0},
    {0, 0, 0, 0}
},
{
    {0, 1, 0, 0},
    {1, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
},
{
    {0, 1, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 0}
},
{
    {1, 1, 1, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
},

{
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 0}
},
{
    {0, 1, 1, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
},

{
    {0, 1, 0, 0},
    {1, 1, 0, 0},
    {1, 0, 0, 0},
    {0, 0, 0, 0}
},
{
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
}
};

struct block_t
{
    int r;
    int c;
    int t;
    block_t operator+(block_t rhs)
    {
        return {r + rhs.r, c + rhs.c, t + rhs.t};
    }
};

int board[21][12];
bool isVisited[19][21][12];

block_t movement[3] = {{1, 0, 0}, {0, 1, 0}, {0, -1, 0}};

bool collision(block_t nowBlock)
{
    for(int r = 0; r < 4; r++)
    {
        for(int c = 0; c < 4; c++)
        {
            if(1 == block[nowBlock.t][r][c] && 1 == board[nowBlock.r + r][nowBlock.c + c])
            {
                return true;
            }
        }
    }

    return false;
}

std::queue<block_t> q;
int result = 0;

void dfs(block_t nowBlock)
{
    isVisited[nowBlock.t][nowBlock.r][nowBlock.c] = true;

    block_t nextBlock;
    for(int i = 0; i < 3; i++)
    {
        nextBlock = nowBlock + movement[i];

        if(isVisited[nextBlock.t][nextBlock.r][nextBlock.c] == true)
        {
            continue;
        }

        if(collision(nextBlock) == true)
        {
            if(0 == i)
            {
                int lineCount = 0;
                for(int r = 0; r < 4; r++)
                {
                    if(nowBlock.r + r >= 20)
                    {
                        break;
                    }

                    int c = 0;
                    for(c = 1; c <= 10; c++)
                    {
                        if(0 == board[nowBlock.r + r][c])
                        {
                            if(c - nowBlock.c >= 0 && c - nowBlock.c < 4)
                            {
                                if(0 == block[nowBlock.t][r][c - nowBlock.c])
                                {
                                    break;
                                }
                            }
                            else
                            {
                                break;
                            }
                        }
                    }

                    if(11 == c)
                    {
                        lineCount++;
                    }
                }

                result = std::max(result, lineCount);
            }
        }
        else
        {
           dfs(nextBlock);
        }
    }

    return;
}

int main()
{
    for(int r = 0; r < 20; r++)
    {
        for(int c = 1; c <= 10; c++)
        {
            scanf("%1d", &board[r][c]);
        }
    }

    for(int r = 0; r <= 20; r++)
    {
        board[r][0] = 1;
        board[r][11] = 1;
    }

    for(int c = 0; c <= 11; c++)
    {
        board[20][c] = 1;
    }

    for(int i = 0; i < 19; i++)
    {
        dfs({0, 1, i});   
    }
    printf("%d", result);

    return 0;
}