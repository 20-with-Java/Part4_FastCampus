#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> S;

int find_index(std::string str)
{
    int startIndex = 0, endIndex = S.size() - 1;

    while(startIndex < endIndex)
    {
        int index = (startIndex + endIndex) / 2;

        if(str.compare(S[index]) <= 0)
        {
            endIndex = index;
        }
        else
        {
            startIndex = index + 1;
        }
    }

    return startIndex;
}

int main()
{
    int N, M;
    char input[501];

    scanf("%d %d", &N ,&M);

    for(int i = 0; i < N; i++)
    {
        scanf("%s", input);
        S.push_back(input);
    }

    std::sort(S.begin(), S.end());

    int count = 0;
    for(int i = 0; i < M; i++)
    {
        scanf("%s", input);
        int length = ((std::string)input).size();
        if(S[find_index(input)].substr(0, length).compare(input) == 0)
        {
            count++;
        }
    }

    printf("%d", count);

    return 0;
}