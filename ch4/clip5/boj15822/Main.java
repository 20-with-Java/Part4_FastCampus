import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] sound1 = new int[n + 1];
        int[] sound2 = new int[n + 1];
        for(int i = 1; i <= n; i++) {
            sound1[i] = sc.nextInt();
        }
        for(int i = 1; i <= n; i++) {
            sound2[i] = sc.nextInt();
        }

        int[][] d = new int[n + 1][n + 1];
        final int INF = 1000000000;
        for(int i = 0 ; i <= n ; i++) {
            for(int j = 0; j <= n; j++) {
                d[i][j] = INF;
            }
        }
        d[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                d[i][j] = min3(d[i-1][j-1], d[i-1][j], d[i][j-1]) + diff(sound1[i], sound2[j]);
            }
        }
        System.out.println(d[n][n]);
    }
    static int diff(int a, int b) {
        return (a - b) * (a - b);
    }
    static int min3(int a, int b, int c) {
        return Math.min(a, Math.min(b, c));
    }
}
