import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int board = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                board = board * 10 + sc.nextInt();
        }
        Set<Integer> check = new HashSet<>();
        check.add(board);
        Queue<SearchData> q = new LinkedList<>();
        q.add(new SearchData(board, 0));

        while (!q.isEmpty()) {
            SearchData data = q.poll();
            int now = data.board;
            int depth = data.depth;
            if (now == 123456780) {
                System.out.println(depth);
                return;
            }
            int[] next = {
                Puzzle.up(now), Puzzle.down(now), Puzzle.left(now), Puzzle.right(now)
            };
            for (int i = 0; i < 4; i++) {
                if (next[i] != -1 && !check.contains(next[i])) {
                    q.add(new SearchData(next[i], depth + 1));
                    check.add(next[i]);
                }
            }
        }
        System.out.println(-1);
    }
}

class SearchData {
    int board;
    int depth;

    SearchData(int board, int depth) {
        this.board = board;
        this.depth = depth;
    }
}

class Puzzle {
    private static final int[][] board = new int[3][3];

    private static int encode() {
        int code = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                code = code * 10 + board[i][j];
            }
        }
        return code;
    }

    private static int decode(int code) {
        int zero = -1;
        for (int i = 2; i >= 0; i--) {
            for (int j = 2; j >= 0; j--) {
                board[i][j] = code % 10;
                if (board[i][j] == 0)
                    zero = i * 3 + j;
                code /= 10;
            }
        }
        return zero;
    }

    static int up(int code) {
        int z = decode(code);
        if (z / 3 == 0) return -1;
        int t = board[z / 3 - 1][z % 3];
        board[z / 3 - 1][z % 3] = 0;
        board[z / 3][z % 3] = t;
        return encode();
    }

    static int down(int code) {
        int z = decode(code);
        if (z / 3 == 2) return -1;
        int t = board[z / 3 + 1][z % 3];
        board[z / 3 + 1][z % 3] = 0;
        board[z / 3][z % 3] = t;
        return encode();
    }

    static int left(int code) {
        int z = decode(code);
        if (z % 3 == 0) return -1;
        int t = board[z / 3][z % 3 - 1];
        board[z / 3][z % 3 - 1] = 0;
        board[z / 3][z % 3] = t;
        return encode();
    }

    static int right(int code) {
        int z = decode(code);
        if (z % 3 == 2) return -1;
        int t = board[z / 3][z % 3 + 1];
        board[z / 3][z % 3 + 1] = 0;
        board[z / 3][z % 3] = t;
        return encode();
    }
}
