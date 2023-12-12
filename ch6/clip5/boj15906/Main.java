import java.util.PriorityQueue;
import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        int gr = sc.nextInt();
        int gc = sc.nextInt();
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int[][] map = new int[n+ 1][n +1];
        int[][][] cost = new int[2][n + 1][n + 1];

        for(int i = 1; i <= n; i++) {
            String s = sc.next();
            for(int j = 1; j <= n; j++) {
                char ch = s.charAt(j - 1);
                if(ch == '#') map[i][j] = 1;
                else map[i][j] = 0;
                cost[0][i][j] = Integer.MAX_VALUE;
                cost[1][i][j] = Integer.MAX_VALUE;
            }
        }
        PriorityQueue<Point> pq = new PriorityQueue<>(
            (a, b) -> a.cost - b.cost
        );

        pq.add(new Point(1, 1, 0, 0));
        cost[0][1][1] = 0;
        while(!pq.isEmpty()) {
            Point now = pq.poll();
            if(now.r == gr && now.c == gc) {
                System.out.println(now.cost);
                return;
            }
            if(cost[now.changed][now.r][now.c] < now.cost) continue;
            for(int i = 0; i < 4; i++) {
                int nr = now.r + dr[i];
                int nc = now.c + dc[i];
                if(!isValid(nr, nc, n)) continue;
                Point next = new Point(nr, nc, 0, now.cost + 1);
                if(cost[0][nr][nc] > next.cost) {
                    cost[0][nr][nc] = next.cost;
                    pq.add(next);
                }
            }
            for(int i = 0; i < 4; i++) {
                int nr = now.r + dr[i];
                int nc = now.c + dc[i];
                int nextCost = now.cost + t * (now.changed == 0 ? 1 : 0) + 1;
                while(true) {
                    if(!isValid(nr, nc, n)) break;
                    if(map[nr][nc] == 1) {
                        if (cost[1][nr][nc] > nextCost) {
                            cost[1][nr][nc] = nextCost;
                            pq.add(new Point(nr, nc, 1, nextCost));
                        }
                        break;
                    }
                    nr += dr[i];
                    nc += dc[i];
                }
            }
        }
    }
    static boolean isValid(int r, int c, int n) {
        return r >= 1 && r <= n && c >= 1 && c <= n;
    }
}

class Point {
    int r, c, changed, cost;
    Point (int r, int c, int changed, int cost) {
        this.r = r;
        this.c = c;
        this.changed = changed;
        this.cost = cost;
    }
}