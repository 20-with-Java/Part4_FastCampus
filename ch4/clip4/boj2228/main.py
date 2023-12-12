import sys

N, M = map(int, sys.stdin.readline().split())
numbers = [0]

for _ in range(N):
    numbers.append(int(sys.stdin.readline()))

dp = [[-1] * (M + 1) for _ in range(N + 1)]
s = [0] * (N + 1)

for i in range(1, N + 1):
    s[i] = s[i - 1] + numbers[i]

def calc(n, m):
    if m == 0:
        return 0
    if n <= 0:
        return -float('inf')
    if dp[n][m] != -1:
        return dp[n][m]
    
    dp[n][m] = calc(n - 1, m)
    
    for i in range(1, n + 1):
        temp = calc(i - 2, m - 1) + (s[n] - s[i - 1])
        dp[n][m] = max(dp[n][m], temp)
    
    return dp[n][m]

print(calc(N, M))
