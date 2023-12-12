import sys

INF = 1000000000

n = int(sys.stdin.readline())
e = int(sys.stdin.readline())

graph = [[INF] * (n + 1) for _ in range(n + 1)]
cost = [INF] * (n + 1)
visited = [False] * (n + 1)

for i in range(n + 1):
    cost[i] = INF

for i in range(e):
    s, d, c = map(int, sys.stdin.readline().split())
    if graph[s][d] > c:
        graph[s][d] = c

start, end = map(int, sys.stdin.readline().split())
cost[start] = 0

for i in range(1, n + 1):
    min_cost = INF
    min_index = -1
    for j in range(1, n + 1):
        if cost[j] < min_cost and not visited[j]:
            min_cost = cost[j]
            min_index = j
    if min_index == -1:
        break

    visited[min_index] = True
    for j in range(1, n + 1):
        if cost[j] > cost[min_index] + graph[min_index][j]:
            cost[j] = cost[min_index] + graph[min_index][j]

print(cost[end])
