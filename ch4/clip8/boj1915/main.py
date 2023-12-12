import sys

n, m = map(int, sys.stdin.readline().split())
arr = []
dp = [[0] * (m + 1) for _ in range(n + 1)]

for _ in range(n):
    row = list(map(int, list(sys.stdin.readline().strip())))
    arr.append(row)

max_size = 0

for i in range(1, n + 1):
    for j in range(1, m + 1):
        if arr[i - 1][j - 1] == 1:
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
            max_size = max(max_size, dp[i][j])

print(max_size * max_size)
