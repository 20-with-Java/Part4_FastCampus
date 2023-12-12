#include <iostream>

int heap[100001];
int heapSize = 0;

bool compare(int a, int b)
{
    if(std::abs(a) == std::abs(b))
    {
        return a > b;
    }
    return std::abs(a) > std::abs(b);
}

void push(int num)
{
    heapSize++;
    heap[heapSize] = num;

    for(int index = heapSize; index > 1; index /= 2)
    {
        if(compare(heap[index / 2], heap[index]))
        {
            std::swap(heap[index / 2], heap[index]);
        }
        else
        {
            break;
        }
    }
    return;
}

void pop()
{
    heap[1] = heap[heapSize];
    heapSize--;

    for(int index = 1; index <= heapSize;)
    {
        if(index * 2 <= heapSize)
        {
            int nextIndex = index * 2;

            if(index * 2 + 1 <= heapSize && compare(heap[index * 2], heap[index * 2 + 1]))
            {
                nextIndex = index * 2 + 1;
            }
            
            if(compare(heap[index], heap[nextIndex]))
            {
                std::swap(heap[index], heap[nextIndex]);
                index = nextIndex;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }

    return;
}

int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);

        if(0 == num)
        {
            if(0 == heapSize)
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n", heap[1]);
                pop();
            }
        }
        else
        {
            push(num);
        }
    }

    return 0;
}