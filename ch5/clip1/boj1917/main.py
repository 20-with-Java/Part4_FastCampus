import sys

def is_range(r, c, n):
    return 1 <= r <= n and 1 <= c <= n

def solve(board):
    n = 6
    dice_check = [0] * (n + 1)

    dr = [-1, 0, 1, 0]
    dc = [0, 1, 0, -1]

    UP, RIGHT, DOWN, LEFT = 0, 1, 2, 3

    def up(c):
        temp = c[0]
        c[0] = c[1]
        c[1] = c[5]
        c[5] = c[4]
        c[4] = temp

    def down(c):
        temp = c[0]
        c[0] = c[4]
        c[4] = c[5]
        c[5] = c[1]
        c[1] = temp

    def left(c):
        temp = c[0]
        c[0] = c[2]
        c[2] = c[5]
        c[5] = c[3]
        c[3] = temp

    def right(c):
        temp = c[0]
        c[0] = c[3]
        c[3] = c[5]
        c[5] = c[2]
        c[2] = temp

    board = [[0] * (n + 1) for _ in range(n + 1)]
    check = [[0] * (n + 1) for _ in range(n + 1)]
    dice_check = [0] * (n + 1)

    start_r, start_c = 0, 0
    for i in range(1, n + 1):
        row = list(map(int, sys.stdin.readline().split()))
        for j in range(1, n + 1):
            board[i][j] = row[j - 1]
            if board[i][j] == 1:
                start_r = i
                start_c = j

    stack = [(start_r, start_c, [1, 2, 3, 4, 5, 6])]
    dice_check[1] = 1
    check[start_r][start_c] = 1

    while stack:
        now_r, now_c, now_dice = stack.pop()
        dice_check[now_dice[0]] = 1

        for i in range(4):
            next_r = now_r + dr[i]
            next_c = now_c + dc[i]

            if is_range(next_r, next_c, n) and board[next_r][next_c] != 0 and check[next_r][next_c] == 0:
                next_dice = now_dice[:]
                if i == UP:
                    up(next_dice)
                elif i == RIGHT:
                    right(next_dice)
                elif i == DOWN:
                    down(next_dice)
                elif i == LEFT:
                    left(next_dice)

                check[next_r][next_c] = 1
                stack.append((next_r, next_c, next_dice))

    is_cube = all(dice_check[1:])
    print("yes" if is_cube else "no")

for _ in range(3):
    solve([])
