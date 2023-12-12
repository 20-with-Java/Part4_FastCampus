import java.util.Scanner;

public class Main {
    static int[] a, s;
    static int[][] d;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        a = new int[n + 1];
        s = new int[n + 1];
        d = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
            s[i] = s[i - 1] + a[i];
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                d[i][j] = -1;
            }
        }
        System.out.println(calc(n, m));
    }

    static int sum(int[] s, int i, int j) {
        return s[j] - s[i - 1];
    }

    static int calc(int n, int m) {
        if (m == 0) return 0;
        if (n <= 0) return -1000000000;
        if (d[n][m] != -1) return d[n][m];
        d[n][m] = calc(n - 1, m);
        for (int i = 1; i <= n; i++) {
            int temp = calc(i - 2, m - 1) + sum(s, i, n);
            if (d[n][m] < temp) d[n][m] = temp;
        }
        return d[n][m];
    }
}