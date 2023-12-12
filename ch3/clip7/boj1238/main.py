import sys
import heapq

def dijkstra(graph, start, end):
    pq = [(0, start)]
    cost = [float('inf')] * (len(graph))
    cost[start] = 0
    
    while pq:
        current_cost, current_node = heapq.heappop(pq)
        
        if cost[current_node] < current_cost:
            continue
        
        for neighbor, neighbor_cost in graph[current_node]:
            if cost[neighbor] > current_cost + neighbor_cost:
                cost[neighbor] = current_cost + neighbor_cost
                heapq.heappush(pq, (cost[neighbor], neighbor))
    
    return cost

n, m, x = map(int, sys.stdin.readline().split())

forward = [[] for _ in range(n + 1)]
backward = [[] for _ in range(n + 1)]

for _ in range(m):
    s, d, c = map(int, sys.stdin.readline().split())
    forward[s].append((d, c))
    backward[d].append((s, c))

forward_cost = dijkstra(forward, x, 0)
backward_cost = dijkstra(backward, x, 0)

answer = 0

for i in range(1, n + 1):
    answer = max(answer, forward_cost[i] + backward_cost[i])

print(answer)
