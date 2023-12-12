import sys
import heapq

def find_minimum_time(N, K, D, rules, W):
    indegree = [0] * (N + 1)
    time = [0] * (N + 1)
    graph = [[] for _ in range(N + 1)]

    for rule in rules:
        X, Y = rule
        graph[X].append(Y)
        indegree[Y] += 1

    q = []

    for i in range(1, N + 1):
        if indegree[i] == 0:
            time[i] = D[i]
            heapq.heappush(q, i)

    while q:
        current = heapq.heappop(q)
        
        for next_node in graph[current]:
            indegree[next_node] -= 1
            time[next_node] = max(time[next_node], time[current] + D[next_node])
            
            if indegree[next_node] == 0:
                heapq.heappush(q, next_node)

    return time[W]

T = int(sys.stdin.readline())

for _ in range(T):
    N, K = map(int, sys.stdin.readline().split())
    D = [0] + list(map(int, sys.stdin.readline().split()))
    rules = [tuple(map(int, sys.stdin.readline().split())) for _ in range(K)]
    W = int(sys.stdin.readline())
    
    result = find_minimum_time(N, K, D, rules, W)
    print(result)
