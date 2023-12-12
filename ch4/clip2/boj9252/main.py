import sys

s1 = sys.stdin.readline().strip()
s2 = sys.stdin.readline().strip()

dp = [[0] * (len(s2) + 1) for _ in range(len(s1) + 1)]

for i in range(1, len(s1) + 1):
    for j in range(1, len(s2) + 1):
        if s1[i - 1] == s2[j - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

length = dp[len(s1)][len(s2)]
print(length)

if length > 0:
    r, c = len(s1), len(s2)
    lcs = [""] * (length + 1)
    while r > 0 and c > 0:
        if s1[r - 1] == s2[c - 1]:
            lcs[length] = s1[r - 1]
            length -= 1
            r -= 1
            c -= 1
        elif dp[r - 1][c] > dp[r][c - 1]:
            r -= 1
        else:
            c -= 1

    print("".join(lcs[1:]))
