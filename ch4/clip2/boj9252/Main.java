import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] s1 = (' ' + sc.next()).toCharArray();
        char[] s2 = (' ' + sc.next()).toCharArray();
        int[][] dp = new int[s1.length][s2.length];
        for (int i = 1; i < s1.length; i++) {
            for (int j = 1; j < s2.length; j++) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        System.out.println(dp[s1.length - 1][s2.length - 1]);
        int r = s1.length - 1, c = s2.length - 1;
        StringBuilder sb = new StringBuilder();
        while (r > 0 && c > 0) {
            if (s1[r] == s2[c]) {
                sb.append(s1[r]);
                r--;
                c--;
            }
            else if (dp[r][c] == dp[r - 1][c]) r--;
            else if (dp[r][c] == dp[r][c - 1]) c--;
        }
        System.out.println(sb.reverse());
    }
}
