import sys
import heapq

INF = 1000000000

n, e = map(int, sys.stdin.readline().split())
if e == 0:
    print(-1)
    sys.exit(0)

graph = [[] for _ in range(n + 1)]

for _ in range(e):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

v1, v2 = map(int, sys.stdin.readline().split())

def dijkstra(start, end):
    cost = [INF] * (n + 1)
    pq = [(0, start)]  # (비용, 정점)
    cost[start] = 0

    while pq:
        current_cost, current_node = heapq.heappop(pq)

        if current_cost > cost[current_node]:
            continue

        for neighbor, weight in graph[current_node]:
            new_cost = cost[current_node] + weight

            if new_cost < cost[neighbor]:
                cost[neighbor] = new_cost
                heapq.heappush(pq, (new_cost, neighbor))

    return cost[end]

result1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, n)
result2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, n)

if result1 >= INF and result2 >= INF:
    print(-1)
else:
    print(min(result1, result2))
