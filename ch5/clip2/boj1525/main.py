from collections import deque

def encode(board):
    code = 0
    for i in range(3):
        for j in range(3):
            code = code * 10 + board[i][j]
    return code

def decode(code, board):
    zero = -1
    for i in range(2, -1, -1):
        for j in range(2, -1, -1):
            board[i][j] = code % 10
            if board[i][j] == 0:
                zero = i * 3 + j
            code //= 10
    return zero

def up(code, board):
    z = decode(code, board)
    if z // 3 == 0:
        return -1
    t = board[z // 3 - 1][z % 3]
    board[z // 3 - 1][z % 3] = 0
    board[z // 3][z % 3] = t
    return encode(board)

def down(code, board):
    z = decode(code, board)
    if z // 3 == 2:
        return -1
    t = board[z // 3 + 1][z % 3]
    board[z // 3 + 1][z % 3] = 0
    board[z // 3][z % 3] = t
    return encode(board)

def left(code, board):
    z = decode(code, board)
    if z % 3 == 0:
        return -1
    t = board[z // 3][z % 3 - 1]
    board[z // 3][z % 3 - 1] = 0
    board[z // 3][z % 3] = t
    return encode(board)

def right(code, board):
    z = decode(code, board)
    if z % 3 == 2:
        return -1
    t = board[z // 3][z % 3 + 1]
    board[z // 3][z % 3 + 1] = 0
    board[z // 3][z % 3] = t
    return encode(board)

board = []
for _ in range(3):
    board.append(list(map(int, input().split())))

initial_state = encode(board)
check = set()
check.add(initial_state)
q = deque([(initial_state, 0)])
result = -1

while q:
    now, depth = q.popleft()
    if now == 123456780:
        result = depth
        break
    next_states = [up(now, board), down(now, board), left(now, board), right(now, board)]
    for next_state in next_states:
        if next_state != -1 and next_state not in check:
            q.append((next_state, depth + 1))
            check.add(next_state)

print(result)
