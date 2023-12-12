import java.util.Scanner;

public class Main {
    static Game game;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int arr[][] = new int[25][15];
        for (int r = 1; r <= 20; r++) {
            String s = sc.next();
            for (int c = 1; c <= 10; c++) {
                arr[r][c] = s.charAt(c - 1) - '0';
            }
        }
        // 벽 테두리를 1로 초기화
        for (int r = 0; r <= 20; r++) {
            arr[r][0] = 1;
            arr[r][11] = 1;
        }
        for (int c = 0; c <= 11; c++) {
            arr[21][c] = 1;
        }
        game = new Game(arr);
        for (int i = 0; i < 19; i++) {
            check[i][1][1] = 1;
            dfs(1, 1, i);
        }
        System.out.println(answer);
    }

    // 하 좌 우 이동가능
    static int[] dr = {0, 0, 0, 1};
    static int[] dc = {0, 1, -1, 0};
    static final int DOWN = 3;
    static int[][][] check = new int[19][22][11];
    static int answer = 0;

    static void dfs(int r, int c, int blockType) {
        check[blockType][r][c] = 1;
        for (int i = 1; i <= 3; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 1 || nr > 20 || nc < 1 || nc > 10) continue;
            if (check[blockType][nr][nc] == 1) continue;
            if (game.check(nr, nc, blockType)) {
                dfs(nr, nc, blockType);
            } else if (i == DOWN) {
                game.add(r, c, blockType);
                answer = Math.max(answer, game.bomb(r));
                game.remove(r, c, blockType);
            }
        }
    }
}

class Game {
    private final int[][] board;

    Game(int[][] b) {
        board = b;
    }

    void add(int r, int c, int blockType) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                board[r + i][c + j] += block[blockType][i][j];
            }
        }
    }

    void remove(int r, int c, int blockType) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                board[r + i][c + j] -= block[blockType][i][j];
            }
        }
    }

    boolean check(int r, int c, int blockType) {
        boolean valid = true;
        int[][] temp = new int[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[r + i][c + j] + block[blockType][i][j] > 1) {
                    valid = false;
                    break;
                }
            }
        }
        return valid;
    }

    int bomb(int r) {
        int cnt = 0;
        for (int i = r; i < r + 4 && i <= 20; i++) {
            boolean isFill = true;
            for (int j = 1; j <= 10; j++) {
                if (board[i][j] == 0) {
                    isFill = false;
                    break;
                }
            }
            if (isFill) cnt++;
        }
        return cnt;
    }

    int[][][] block = {
        {
            {1, 1, 0, 0},
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {1, 0, 0, 0},
            {1, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {1, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },

        {
            {1, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {1, 1, 1, 0},
            {1, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 1, 0},
            {1, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 0, 0, 0}
        },
        {
            {1, 1, 1, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },

        {
            {1, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },

        {
            {1, 0, 0, 0},
            {1, 1, 0, 0},
            {1, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 1, 0, 0},
            {1, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },

        {
            {1, 0, 0, 0},
            {1, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 1, 1, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 1, 0, 0},
            {1, 1, 0, 0},
            {1, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        }
    };
}