import sys

n = int(sys.stdin.readline().strip())
a = list(map(int, sys.stdin.readline().split()))

d = [0] * n
d[0] = a[0]
ans = d[0]

for i in range(1, n):
    d[i] = max(a[i], d[i - 1] + a[i])
    ans = max(ans, d[i])

left = [0] * n
right = [0] * n

left[0] = a[0]
right[n - 1] = a[n - 1]

for i in range(1, n):
    left[i] = max(left[i - 1] + a[i], a[i])

for i in range(n - 2, -1, -1):
    right[i] = max(right[i + 1] + a[i], a[i])

for i in range(1, n - 1):
    ans = max(ans, left[i - 1] + right[i + 1])

sys.stdout.write(str(ans) + "\n")
