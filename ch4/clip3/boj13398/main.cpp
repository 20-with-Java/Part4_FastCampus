#include <iostream>

int main()
{
    int n, num;
    int sum[2] = {0, 0}, maxSum[2] = {-1001, -1001}, minNum = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        sum[0] += num;
        sum[1] += num;
       
        maxSum[0] = std::max(sum[0], maxSum[0]);
        maxSum[1] = std::max(sum[1], maxSum[1]);
        
        if(num < 0)
        {
            if(minNum > num)
            {
                sum[1] += minNum;
                sum[1] -= num;
                minNum = num;
            }
            
            if(sum[0] - num >= sum[1])
            {
                sum[1] = sum[0] - num;
                minNum = num;
            }

            if(sum[0] < 0)
            {
                sum[0] = 0;
            }
        }
    }

    printf("%d", std::max(maxSum[0], maxSum[1]));

    return 0;
}