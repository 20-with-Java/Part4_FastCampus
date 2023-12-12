import heapq

n, t, gr, gc = map(int, input().split())
grid = []
for _ in range(n):
    row = input()
    grid.append(row)

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def is_valid(x, y):
    return 0 <= x < n and 0 <= y < n

def dijkstra():
    min_turns = [[[float('inf')] * (n) for _ in range(n)] for _ in range(2)]
    min_turns[0][0][0] = 0
    pq = [(0, 0, 0, 0)]  # (turns, x, y, changed)
    
    while pq:
        turns, x, y, changed = heapq.heappop(pq)
        if x == gc - 1 and y == gr - 1:
            return turns
        
        if min_turns[changed][y][x] < turns:
            continue

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if is_valid(nx, ny) and min_turns[0][ny][nx] > turns + 1:
                min_turns[0][ny][nx] = turns + 1
                heapq.heappush(pq, (turns + 1, nx, ny, 0))
        
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            while is_valid(nx, ny) and grid[ny][nx] == '.':
                nx += dx[i]
                ny += dy[i]

            if is_valid(nx, ny):
                nturns = turns + t * (1 - changed) + 1
                if min_turns[1][ny][nx] > nturns:
                    min_turns[1][ny][nx] = nturns
                    heapq.heappush(pq, (nturns, nx, ny, 1))

print(dijkstra())
