import sys

sys.setrecursionlimit(10**6)

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
arr.insert(0, 0)
m = int(sys.stdin.readline())

dp = [[-1] * (n + 1) for _ in range(n + 1)]

def is_palindrome(start, end):
    if start >= end:
        return 1
    
    if dp[start][end] != -1:
        return dp[start][end]

    if arr[start] != arr[end]:
        return 0
    else:
        dp[start][end] = is_palindrome(start + 1, end - 1)
        return dp[start][end]


answers = []
for _ in range(m):
    s, e = map(int, sys.stdin.readline().split())
    answers.append(is_palindrome(s, e))

for ans in answers:
    sys.stdout.write(str(ans) + "\n")
