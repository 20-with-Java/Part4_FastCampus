#include <iostream>
#include <queue>

int main()
{
    int N, num;
    std::priority_queue<int, std::vector<int>, std::greater<int>> bigNumber;
    std::priority_queue<int, std::vector<int>, std::less<int>> smallNumber;

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &num);

        if(i % 2 == 0)
        {
            if(bigNumber.empty() == false && bigNumber.top() < num)
            {
                smallNumber.push(bigNumber.top());
                bigNumber.pop();
                bigNumber.push(num);
            }
            else
            {
                smallNumber.push(num);
            }
        }
        else
        {
            if(smallNumber.top() > num)
            {
                bigNumber.push(smallNumber.top());
                smallNumber.pop();
                smallNumber.push(num);
            }
            else
            {
                bigNumber.push(num);
            }
        }

        printf("%d\n", smallNumber.top());
    }

    return 0;
}