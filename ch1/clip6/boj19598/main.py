import heapq

n = int(input())
meetings = []

for _ in range(n):
    start, end = map(int, input().split())
    meetings.append((start, end))

meetings.sort(key=lambda x: (x[0], x[1]))
pq = []  # 끝나는 시간을 저장하는 우선순위 큐
ans = 1

for meeting in meetings:
    if not pq:
        heapq.heappush(pq, meeting[1])
        continue
    
    while pq and pq[0] <= meeting[0]:
        heapq.heappop(pq)
    heapq.heappush(pq, meeting[1])
    ans = max(ans, len(pq))

print(ans)
