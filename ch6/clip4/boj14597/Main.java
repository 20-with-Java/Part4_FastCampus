import java.util.Arrays;
import java.util.Scanner;


public class Main {
    static int[][] dp;
    static int[][][] image;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        final int MAX_VALUE = 1000000000;
        image = new int[2][h + 2][w + 2];
        dp = new int[h + 2][w + 2];

        for (int img = 0; img <= 1; img++) {
            for (int i = 1; i <= h; i++) {
                for (int j = 1; j <= w; j++) {
                    image[img][i][j] = sc.nextInt();
                }
            }
        }
        for(int i = 1; i <= h; i++) {
            Arrays.fill(dp[i], MAX_VALUE);
        }
        int answer = MAX_VALUE;
        for(int r = 1; r <= h; r++) {
            for(int c = 1; c <= w; c++) {
                int case1 = dp[r - 1][c - 1];
                int case2 = dp[r - 1][c];
                int case3 = dp[r - 1][c + 1];
                int diff = image[0][r][c] - image[1][r][c];
                dp[r][c] = Math.min(case1, Math.min(case2, case3)) +
                    (diff * diff);
            }
        }
        for(int c = 1; c <= w; c++) {
            answer = Math.min(answer, dp[h][c]);
        }
        System.out.println(answer);
    }
}
