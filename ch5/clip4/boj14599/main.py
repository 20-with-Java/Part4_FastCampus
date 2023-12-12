class Game:
    def __init__(self, board):
        self.board = board

    def add(self, r, c, block_type):
        for i in range(4):
            for j in range(4):
                self.board[r + i][c + j] += block[block_type][i][j]

    def remove(self, r, c, block_type):
        for i in range(4):
            for j in range(4):
                self.board[r + i][c + j] -= block[block_type][i][j]

    def check(self, r, c, block_type):
        for i in range(4):
            for j in range(4):
                if self.board[r + i][c + j] + block[block_type][i][j] > 1:
                    return False
        return True

    def bomb(self, r):
        cnt = 0
        for i in range(r, min(r + 4, 21)):
            if all(self.board[i][1:11]):
                cnt += 1
        return cnt
    
block = [
    [
        [1, 1, 0, 0],
        [1, 0, 0, 0],
        [1, 0, 0, 0],
        [0, 0, 0, 0]
    ],
    [
        [1, 0, 0, 0],
        [1, 1, 1, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0]
    ],
    [
        [0, 1, 0, 0],
        [0, 1, 0, 0],
        [1, 1, 0, 0],
        [0, 0, 0, 0]
    ],
    [
        [1, 1, 1, 0],
        [0, 0, 1, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0]
    ],
    [
        [1, 1, 0, 0],
        [0, 1, 0, 0],
        [0, 1, 0, 0],
        [0, 0, 0, 0]
    ],
    [
        [1, 1, 1, 0],
        [1, 0, 0, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0]
    ],
    [
        [1, 0, 0, 0],
        [1, 0, 0, 0],
        [1, 1, 0, 0],
        [0, 0, 0, 0]
    ],
    [
        [0, 0, 1, 0],
        [1, 1, 1, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0]
    ],
    [
        [1, 0, 0, 0],
        [1, 0, 0, 0],
        [1, 0, 0, 0],
        [1, 0, 0, 0]
    ],
    [
        [1, 1, 1, 1],
        [0, 0, 0, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0]
    ],
    [
        [1, 1, 0, 0],
        [1, 1, 0, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0]
    ],
    [
        [1, 0, 0, 0],
        [1, 1, 0, 0],
        [1, 0, 0, 0],
        [0, 0, 0, 0]
    ],
    [
        [0, 1, 0, 0],
        [1, 1, 1, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0]
    ],
    [
        [0, 1, 0, 0],
        [1, 1, 0, 0],
        [0, 1, 0, 0],
        [0, 0, 0, 0]
    ],
    [
        [1, 1, 1, 0],
        [0, 1, 0, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0]
    ],
    [
        [1, 0, 0, 0],
        [1, 1, 0, 0],
        [0, 1, 0, 0],
        [0, 0, 0, 0]
    ],
    [
        [0, 1, 1, 0],
        [1, 1, 0, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0]
    ],
    [
        [0, 1, 0, 0],
        [1, 1, 0, 0],
        [1, 0, 0, 0],
        [0, 0, 0, 0]
    ],
    [
        [1, 1, 0, 0],
        [0, 1, 1, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0]
    ]
]

def dfs(r, c, block_type):
    global answer
    check[block_type][r][c] = 1
    for i in range(3):
        nr = r + dr[i]
        nc = c + dc[i]
        if 1 <= nr <= 20 and 1 <= nc <= 10 and check[block_type][nr][nc] == 0:
            if game.check(nr, nc, block_type):
                dfs(nr, nc, block_type)
            elif i == 2:
                game.add(r, c, block_type)
                answer = max(answer, game.bomb(r))
                game.remove(r, c, block_type)

game = None
answer = 0
dr = [0, 0, 1]
dc = [1, -1, 0]
check = [[[0] * 12 for _ in range(22)] for _ in range(19)]
board = [[0] * 15 for _ in range(25)]

for r in range(1, 21):
    s = input()
    for c in range(1, 11):
        board[r][c] = int(s[c - 1])

for r in range(22):
    board[r][0] = 1
    board[r][11] = 1
for c in range(12):
    board[21][c] = 1

game = Game(board)

for i in range(19):
    check[i][1][1] = 1
    dfs(1, 1, i)

print(answer)
