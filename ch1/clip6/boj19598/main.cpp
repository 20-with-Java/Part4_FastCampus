#include <iostream>
#include <algorithm>
#include <queue>

struct meeting_t
{
    int startTime;
    int endTime;

    bool operator()(meeting_t a, meeting_t b)
    {
        return a.endTime > b.endTime;
    }
};

bool ascending_start_time(meeting_t a, meeting_t b)
{
    return a.startTime < b.startTime;
}

int main()
{
    int N;
    meeting_t meeting[100000];
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &meeting[i].startTime, &meeting[i].endTime);
    }

    std::sort(&meeting[0], &meeting[N], ascending_start_time);

    std::priority_queue<meeting_t, std::vector<meeting_t>, meeting_t> pq;
    int result = 0;

    for(int i = 0; i < N; i++)
    {
        while(pq.empty() == false && pq.top().endTime <= meeting[i].startTime)
        {
            pq.pop();
        }

        pq.push(meeting[i]);
        if(pq.size() > result)
        {
            result = pq.size();
        }
    }

    printf("%d", result);

    return 0;
}