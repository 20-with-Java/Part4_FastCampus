import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = 6;
        for (int tc = 1; tc <= 3; tc++) {
            int[][] board = new int[n + 1][n + 1];
            int[][] check = new int[n + 1][n + 1];
            int[] diceCheck = new int[n + 1]; // 좌표 체크와 주사위 숫자를 체크할 배열 생성

            int[] dr = {-1, 0, 1, 0};
            int[] dc = {0, 1, 0, -1};
            final int UP = 0;
            final int RIGHT = 1;
            final int DOWN = 2;
            final int LEFT = 3;

            int startR = 0, startC = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    board[i][j] = sc.nextInt();
                    if (board[i][j] == 1) {
                        startR = i;
                        startC = j;
                    }
                }
            }

            Dice dice = new Dice();
            Stack<Pair<Point, Dice>> stack = new Stack<>();
            stack.push(new Pair<>(new Point(startR, startC), dice));
            diceCheck[dice.getTop()] = 1;
            check[startR][startC] = 1;
            while (!stack.isEmpty()) {
                Pair<Point, Dice> pair = stack.pop();
                Point now = pair.first;
                Dice nowDice = pair.second;
                diceCheck[nowDice.getTop()] = 1;
                for (int i = 0; i < 4; i++) {
                    Point next = new Point(now.r + dr[i], now.c + dc[i]);
                    if (isRange(next.r, next.c, n) && board[next.r][next.c] != 0 && check[next.r][next.c] == 0) {
                        Dice nextDice = new Dice(nowDice.getCube());
                        switch (i) {
                            case UP -> nextDice.up();
                            case RIGHT -> nextDice.right();
                            case DOWN -> nextDice.down();
                            case LEFT -> nextDice.left();
                        }
                        check[next.r][next.c] = 1;
                        stack.push(new Pair<>(new Point(next.r, next.c), nextDice));
                    }
                }
            }
            boolean isCube = true;
            for(int i = 1; i <= 6; i++) {
                if(diceCheck[i] == 0) {
                    isCube = false;
                    break;
                }
            }
            System.out.println(isCube ? "yes" : "no");

        }
    }

    static boolean isRange(int r, int c, int n) {
        return r >= 1 && r <= n && c >= 1 && c <= n;
    }
}
class Pair<T, U> {
    T first;
    U second;

    public Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }
}

class Point {
    int r;
    int c;

    public Point(int r, int c) {
        this.r = r;
        this.c = c;
    }
}

class Dice {
    private int[] cube;
    /*
        _____
       / 1 / |
       ----|3|
       | 2 |/
       ----/
    */
    public Dice() {
        cube = new int[7];
        for (int i = 1; i <= 6; i++) {
            cube[i] = i;
        }
    }

    public Dice(int[] c) {
        cube = new int[7];
        for (int i = 1; i <= 6; i++) {
            cube[i] = c[i];
        }
    }

    public int getTop() {
        return cube[1];
    }

    public int[] getCube() {
        return cube;
    }

    public void up() {
        int temp = cube[1];
        cube[1] = cube[2];
        cube[2] = cube[6];
        cube[6] = cube[5];
        cube[5] = temp;
    }

    public void down() {
        int temp = cube[1];
        cube[1] = cube[5];
        cube[5] = cube[6];
        cube[6] = cube[2];
        cube[2] = temp;
    }

    public void left() {
        int temp = cube[1];
        cube[1] = cube[3];
        cube[3] = cube[6];
        cube[6] = cube[4];
        cube[4] = temp;
    }

    public void right() {
        int temp = cube[1];
        cube[1] = cube[4];
        cube[4] = cube[6];
        cube[6] = cube[3];
        cube[3] = temp;
    }
}

