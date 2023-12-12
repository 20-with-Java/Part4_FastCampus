#include <iostream>

int cube[25];

void rollUp()
{
    int temp[2] = {cube[2], cube[4]};
    cube[2] = cube[6];
    cube[4] = cube[8];
    cube[6] = cube[10];
    cube[8] = cube[12];
    cube[10] = cube[23];
    cube[12] = cube[21];
    cube[23] = temp[0];
    cube[21] = temp[1];

    return;
}

void rollRight()
{
    int temp[2] = {cube[5], cube[6]};
    cube[5] = cube[13];
    cube[6] = cube[14];
    cube[13] = cube[21];
    cube[14] = cube[22];
    cube[21] = cube[17];
    cube[22] = cube[18];
    cube[17] = temp[0];
    cube[18] = temp[1];

    return;
}

void rollClockwise()
{
    int temp[2] = {cube[3], cube[4]};
    cube[3] = cube[16];
    cube[4] = cube[14];
    cube[16] = cube[10];
    cube[14] = cube[9];
    cube[10] = cube[17];
    cube[9] = cube[19];
    cube[17] = temp[0];
    cube[19] = temp[1];

    return;
}

bool isCorrect()
{
    for(int j = 0; j < 6; j++)
    {
        for(int i = 2; i <= 4; i++)
        {
            if(cube[j * 4 + i] != cube[j * 4 + 1])
            {
                return false;
            }
        }
    }

    return true;
}

void (*roll[3])(void) = {rollUp, rollRight, rollClockwise};

int main()
{
    for(int i = 1; i <= 24; i++)
    {
        scanf("%d", &cube[i]);
    }

    for(int j = 0; j < 3; j++)
    {
        roll[j]();
        if(isCorrect() == true)
        {
            printf("1");
            return 0;
        }
        
        roll[j]();
        roll[j]();
        if(isCorrect() == true)
        {
            printf("1");
            return 0;
        }

        roll[j]();
    }

    printf("0");

    return 0;
}