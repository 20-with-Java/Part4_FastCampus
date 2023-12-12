import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        final int INF = 1000000000;
        int n = sc.nextInt(), e = sc.nextInt();
        int[][] graph = new int[n + 1][n + 1];
        int[] cost = new int[n + 1];
        boolean[] visited = new boolean[n + 1];

        for(int i = 0; i < n + 1; i++) {
            cost[i] = INF;
            for(int j = 0; j < n + 1; j++) {
                graph[i][j] = INF;
            }
        }
        for (int i = 0; i < e; i++) {
            int s = sc.nextInt(), d = sc.nextInt(), c = sc.nextInt();
            if(graph[s][d] > c) graph[s][d] = c;
        }
        int start = sc.nextInt(), end = sc.nextInt();
        cost[start] = 0;
        for(int i = 1; i <= n; i++) {
            int min = INF;
            int minIndex = -1;
            for(int j = 1; j <= n; j++) {
                if(cost[j] < min && !visited[j]) {
                    min = cost[j];
                    minIndex = j;
                }
            }
            if(minIndex == -1) break;

            visited[minIndex] = true;
            for(int j = 1; j <= n; j++) {
                if(cost[j] > cost[minIndex] + graph[minIndex][j]) {
                    cost[j] = cost[minIndex] + graph[minIndex][j];
                }
            }
        }
        System.out.println(cost[end]);
    }
}
