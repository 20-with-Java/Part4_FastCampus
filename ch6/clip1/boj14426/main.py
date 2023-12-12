import sys

n, m = map(int, sys.stdin.readline().split())
s = []
p = []

for _ in range(n):
    s.append(sys.stdin.readline().strip())

for _ in range(m):
    p.append(sys.stdin.readline().strip())

s.sort()
cnt = 0

for str in p:
    left = 0
    right = n - 1
    while left <= right:
        mid = (left + right) // 2
        target = s[mid][:len(str)]
        if str == target:
            cnt += 1
            break
        elif str > target:
            left = mid + 1
        else:
            right = mid - 1

print(cnt)
