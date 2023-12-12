import sys
import heapq

INF = 1000000000

m, n = map(int, sys.stdin.readline().split())
graph = []
cost = [[INF] * m for _ in range(n)]
cost[0][0] = 0

for _ in range(n):
    row = list(map(int, list(sys.stdin.readline().strip())))
    graph.append(row)

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

pq = [(0, 0, 0)]  # 튜플로 요소를 추가

while pq:
    now = heapq.heappop(pq)
    row, col, current_cost = now  # 요소를 추출

    if current_cost > cost[row][col]:
        continue

    if row == n - 1 and col == m - 1:
        break

    for i in range(4):
        nr = row + dr[i]
        nc = col + dc[i]

        if nr < 0 or nr >= n or nc < 0 or nc >= m:
            continue

        new_cost = current_cost + graph[nr][nc]

        if new_cost < cost[nr][nc]:
            cost[nr][nc] = new_cost
            heapq.heappush(pq, (nr, nc, new_cost))  # 튜플로 요소를 추가

sys.stdout.write(str(cost[n - 1][m - 1]))
