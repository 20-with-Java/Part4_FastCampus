import sys
import heapq

n = int(input())
pq = []

for _ in range(n):
    row = list(map(int, sys.stdin.readline().split()))
    for num in row:
        heapq.heappush(pq, num)
        if len(pq) > n:
            heapq.heappop(pq)

print(pq[0])
