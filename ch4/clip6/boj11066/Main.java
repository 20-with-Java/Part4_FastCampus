import java.util.Scanner;

public class Main {
    static final int INF = 1000000000;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int k = sc.nextInt();
            int[] file = new int[k + 1];
            int[] sum = new int[k + 1];
            for (int i = 1; i <= k; i++) {
                file[i] = sc.nextInt();
                sum[i] = sum[i - 1] + file[i];
            }
            int[][] d = new int[k + 1][k + 1];

            for (int i = 1; i <= k; i++) {
                for (int j = 1; j <= k; j++) {
                    d[i][j] = INF;
                }
                d[i][i] = 0;
            }
            for (int length = 1; length <= k - 1; length++) {
                for (int i = 1; i <= k - length; i++) {
                    int end = i + length;
                    if(end > k) break;
                    for (int p = i; p < end; p++) {
                        d[i][end] = Math.min(d[i][end], d[i][p] + d[p + 1][end] + prefixSum(sum, i, end));
                    }
                }
            }
            System.out.println(d[1][k]);
        }
    }

    static int prefixSum(int[] sum, int i, int j) {
        return sum[j] - sum[i - 1];
    }

}