#include <iostream>
#include <cmath>
#include <queue>
#include <set>

int find_zero_position(int board)
{
    for(int i = 0; i < 8; i++, board /= 10)
    {
        if(board % 10 == 0)
        {
            return i;
        }
    }
    return 8;
}

int swap_board(int board, int posZero, int posNum)
{
    int tempBoard, i;
    for(tempBoard = board, i = 0; i < posNum; i++, tempBoard /= 10){;}
    tempBoard %= 10;

    board -= tempBoard * (int)pow(10, posNum);
    board += tempBoard * (int)pow(10, posZero);

    return board;
}

struct node_t
{
    int board;
    int moveCount;
};

int main()
{
    int board = 0, num;
    std::set<int> boardSet;
    std::queue<node_t> q;

    for(int i = 0; i < 9; i++)
    {
        scanf("%d", &num);
        board = board * 10 + num;
    }

    boardSet.insert(board);
    for(q.push({board, 0}); q.empty() == false; q.pop())
    {
        int frontBoard = q.front().board, moveCount = q.front().moveCount, nextBoard;
        int zero_position = find_zero_position(frontBoard);

        if(frontBoard == 123456780)
        {
            printf("%d", moveCount);
            return 0;
        }

        if(zero_position >= 3)
        {
            nextBoard = swap_board(frontBoard, zero_position, zero_position - 3);
            if(boardSet.find(nextBoard) == boardSet.end())
            {
                boardSet.insert(nextBoard);
                q.push({nextBoard, moveCount + 1});
            }
        }

        if(zero_position < 6)
        {
            nextBoard = swap_board(frontBoard, zero_position, zero_position + 3);
            if(boardSet.find(nextBoard) == boardSet.end())
            {
                boardSet.insert(nextBoard);
                q.push({nextBoard, moveCount + 1});
            }
        }
                
        if(zero_position % 3 != 0)
        {
            nextBoard = swap_board(frontBoard, zero_position, zero_position - 1);
            if(boardSet.find(nextBoard) == boardSet.end())
            {
                boardSet.insert(nextBoard);
                q.push({nextBoard, moveCount + 1});
            }
        }

        if(zero_position % 3 != 2)
        {
            nextBoard = swap_board(frontBoard, zero_position, zero_position + 1);
            if(boardSet.find(nextBoard) == boardSet.end())
            {
                boardSet.insert(nextBoard);
                q.push({nextBoard, moveCount + 1});
            }
        }
    }
    printf("-1");

    return 0;
}