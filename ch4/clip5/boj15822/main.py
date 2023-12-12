import sys

n = int(sys.stdin.readline().strip())

sound1 = list(map(int, sys.stdin.readline().split()))
sound2 = list(map(int, sys.stdin.readline().split()))
sound1.insert(0, 0)
sound2.insert(0, 0)

d = [[1000000000] * (n + 1) for _ in range(n + 1)]
d[0][0] = 0

for i in range(1, n + 1):
    for j in range(1, n + 1):
        cost = (sound1[i] - sound2[j]) ** 2
        d[i][j] = min(d[i - 1][j - 1], d[i - 1][j], d[i][j - 1]) + cost

print(d[n][n])
