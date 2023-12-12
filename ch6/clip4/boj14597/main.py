h, w = map(int, input().split())
image = [[[-1] * (w + 2) for _ in range(h + 2)] for _ in range(2)]
dp = [[float('inf')] * (w + 2) for _ in range(h + 2)]

for i in range(w + 2):
    dp[0][i] = 0

for img in range(2):
    for i in range(1, h + 1):
        row = list(map(int, input().split()))
        for j in range(1, w + 1):
            image[img][i][j] = row[j - 1]

for i in range(1, h + 1):
    for j in range(1, w + 1):
        dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]) + (image[0][i][j] - image[1][i][j]) ** 2

print(min(dp[h][1:w + 1]))
