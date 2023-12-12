import sys

def min_cost_to_merge_files(k, file):
    sum_arr = [0] * (k + 1)
    dp = [[0] * (k + 1) for _ in range(k + 1)]
    INF = 1000000000

    for i in range(1, k + 1):
        sum_arr[i] = sum_arr[i - 1] + file[i - 1]

    for i in range(1, k + 1):
        for j in range(1, k + 1):
            dp[i][j] = INF

    for i in range(1, k + 1):
        dp[i][i] = 0

    for length in range(2, k + 1):
        for i in range(1, k - length + 2):
            j = i + length - 1
            for p in range(i, j):
                dp[i][j] = min(dp[i][j], dp[i][p] + dp[p + 1][j] + sum_arr[j] - sum_arr[i - 1])

    return dp[1][k]

t = int(sys.stdin.readline())
results = []

for _ in range(t):
    k = int(sys.stdin.readline())
    file = list(map(int, sys.stdin.readline().split()))
    result = min_cost_to_merge_files(k, file)
    results.append(result)

for result in results:
    print(result)
