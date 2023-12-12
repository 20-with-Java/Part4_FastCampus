import sys
import heapq

N, M, K = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(N + 1)]
for _ in range(M):
    A, B, C = map(int, sys.stdin.readline().split())
    graph[A].append((B, C))
    graph[B].append((A, C))

INF = float('inf')
dist = [[INF] * (K + 1) for _ in range(N + 1)]
dist[1][0] = 0

pq = [(0, 1, 0)]

while pq:
    cost, node, used_roads = heapq.heappop(pq)

    if cost > dist[node][used_roads]:
        continue

    for neighbor, neighbor_cost in graph[node]:
        if dist[neighbor][used_roads] > cost + neighbor_cost:
            dist[neighbor][used_roads] = cost + neighbor_cost
            heapq.heappush(pq, (dist[neighbor][used_roads], neighbor, used_roads))

        if used_roads < K and dist[neighbor][used_roads + 1] > cost:
            dist[neighbor][used_roads + 1] = cost
            heapq.heappush(pq, (dist[neighbor][used_roads + 1], neighbor, used_roads + 1))

answer = min(dist[N])
print(answer)
