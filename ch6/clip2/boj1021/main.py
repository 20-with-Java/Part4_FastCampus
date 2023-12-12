from collections import deque

n, m = map(int, input().split())
arr = list(map(int, input().split()))
q = deque(range(1, n + 1))
answer = 0

for i in range(m):
    cnt = 0
    while q[0] != arr[i]:
        q.rotate(1)
        cnt += 1
    answer += min(len(q) - cnt, cnt)
    q.popleft()

print(answer)
