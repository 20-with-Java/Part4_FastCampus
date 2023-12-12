import sys
import heapq

n = int(sys.stdin.readline())
pq = []

for _ in range(n):
    x = int(sys.stdin.readline())
    if x == 0:
        if not pq:
            sys.stdout.write("0\n")
        else:
            _, num = heapq.heappop(pq)
            sys.stdout.write(str(num) + "\n")
    else:
        heapq.heappush(pq, (abs(x), x))
