import sys
import heapq

INF = 1000000000

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

graph = [[] for _ in range(n + 1)]
cost = [INF] * (n + 1)
path = [0] * (n + 1)

for i in range(m):
    s, d, c = map(int, sys.stdin.readline().split())
    graph[s].append((d, c))

start, end = map(int, sys.stdin.readline().split())

pq = []
heapq.heappush(pq, (0, start))
cost[start] = 0

while pq:
    now_cost, now = heapq.heappop(pq)
    if cost[now] < now_cost:
        continue
    for next_city, next_cost in graph[now]:
        if cost[now] + next_cost < cost[next_city]:
            cost[next_city] = cost[now] + next_cost
            heapq.heappush(pq, (cost[next_city], next_city))
            path[next_city] = now

print(cost[end])

path_stack = []
now = end
while now != 0:
    path_stack.append(now)
    now = path[now]

print(len(path_stack))
print(" ".join(map(str, reversed(path_stack))))
