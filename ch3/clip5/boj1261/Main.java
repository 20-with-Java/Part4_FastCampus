import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        final int INF = 1000000000;
        int m = sc.nextInt(), n = sc.nextInt();
        int[][] graph = new int[n + 1][m + 1];
        int[][] cost = new int[n + 1][m + 1];
        for(int i = 1; i <= n; i++) {
            char[] input = sc.next().toCharArray();
            for(int j = 1; j <= m; j++) {
                graph[i][j] = input[j - 1] - '0';
                cost[i][j] = INF;
            }
        }
        PriorityQueue<Point> pq = new PriorityQueue<>((o1, o2) -> {
            return o1.cost - o2.cost;
        });
        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};
        pq.offer(new Point(1, 1, 0));
        cost[1][1] = 0;
        while(!pq.isEmpty()) {
            Point now = pq.poll();
            if(cost[now.row][now.col] < now.cost) continue;
            if(now.row == n && now.col == m) break;
            for(int i = 0; i < 4; i++) {
                int nr = now.row + dr[i];
                int nc = now.col + dc[i];
                if(nr < 1 || nr > n || nc < 1 || nc > m) continue;
                if(cost[nr][nc] > cost[now.row][now.col] + graph[nr][nc]) {
                    cost[nr][nc] = cost[now.row][now.col] + graph[nr][nc];
                    pq.offer(new Point(nr, nc, cost[nr][nc]));
                }
            }
        }
        System.out.println(cost[n][m]);
    }
}

class Point {
    int row, col, cost;
    public Point(int row, int col, int cost) {
        this.row = row;
        this.col = col;
        this.cost = cost;
    }
}