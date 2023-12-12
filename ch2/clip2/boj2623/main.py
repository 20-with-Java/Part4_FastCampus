import sys
from collections import deque

def determine_singer_order(N, M, orders):
    indegree = [0] * (N + 1)
    graph = [[] for _ in range(N + 1)]
    
    for order in orders:
        cnt, *singers = order
        for i in range(cnt - 1):
            a, b = singers[i], singers[i + 1]
            graph[b].append(a)  # 순서를 뒤집어서 저장
            indegree[a] += 1
    
    result = []
    queue = deque()
    
    for i in range(1, N + 1):
        if indegree[i] == 0:
            queue.append(i)
    
    while queue:
        current = queue.popleft()
        result.append(current)
        
        for next_node in graph[current]:
            indegree[next_node] -= 1
            
            if indegree[next_node] == 0:
                queue.append(next_node)
    
    if len(result) != N:
        return [0]  # 남일이가 순서를 정하는 것이 불가능한 경우
    
    return result[::-1]  # 순서를 뒤집어서 반환

N, M = map(int, sys.stdin.readline().split())
orders = [list(map(int, sys.stdin.readline().split())) for _ in range(M)]

singer_order = determine_singer_order(N, M, orders)
for order in singer_order:
    print(order)
