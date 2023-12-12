import sys
from collections import deque

def line_up_students(N, M, comparisons):
    indegree = [0] * (N + 1)
    graph = [[] for _ in range(N + 1)]

    for comparison in comparisons:
        A, B = comparison
        graph[A].append(B)
        indegree[B] += 1

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

    return result

N, M = map(int, sys.stdin.readline().split())
comparisons = [tuple(map(int, sys.stdin.readline().split())) for _ in range(M)]

order = line_up_students(N, M, comparisons)
print(*order)
