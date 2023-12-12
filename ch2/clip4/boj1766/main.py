import sys
import heapq

def solve_problem(N, M, preferences):
    indegree = [0] * (N + 1)
    graph = [[] for _ in range(N + 1)]

    for preference in preferences:
        A, B = preference
        graph[A].append(B)
        indegree[B] += 1

    pq = []

    for i in range(1, N + 1):
        if indegree[i] == 0:
            heapq.heappush(pq, i)

    result = []

    while pq:
        current = heapq.heappop(pq)
        result.append(current)

        for next_node in graph[current]:
            indegree[next_node] -= 1

            if indegree[next_node] == 0:
                heapq.heappush(pq, next_node)

    return result

N, M = map(int, sys.stdin.readline().split())
preferences = [tuple(map(int, sys.stdin.readline().split())) for _ in range(M)]

order = solve_problem(N, M, preferences)
print(*order)
