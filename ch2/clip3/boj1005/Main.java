import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 0; tc < t; tc++) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] time = new int[n + 1];
            int[] dp = new int[n + 1];
            int[] indegree = new int[n + 1];
            int[][] adj = new int[n + 1][n + 1];
            for (int i = 1; i <= n; i++) {
                time[i] = sc.nextInt();
            }
            for (int i = 0; i < k; i++) {
                int a = sc.nextInt();
                int b = sc.nextInt();
                adj[a][b] = 1;
                indegree[b]++;
            }
            Queue<Integer> q = new LinkedList<>();
            for (int i = 1; i <= n; i++) {
                if (indegree[i] == 0) {
                    q.offer(i);
                    dp[i] = time[i];
                }
            }
            while (!q.isEmpty()) {
                int now = q.poll();
                for (int next = 1; next <= n; next++) {
                    if (adj[now][next] == 1) {
                        indegree[next]--;
                        dp[next] = Math.max(dp[next], dp[now] + time[next]);
                        if (indegree[next] == 0) q.offer(next);
                    }
                }
            }
            int w = sc.nextInt();
            System.out.println(dp[w]);
        }
    }
}
