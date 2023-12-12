import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt(), x = sc.nextInt();
        List<Edge>[] forward = new ArrayList[n + 1];
        List<Edge>[] backward = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            forward[i] = new ArrayList<>();
            backward[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int s = sc.nextInt(), d = sc.nextInt(), c = sc.nextInt();
            forward[s].add(new Edge(d, c));
            backward[d].add(new Edge(s, c));
        }
        int[] forwardCost = dijkstra(forward, x);
        int[] backwardCost = dijkstra(backward, x);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = Math.max(ans, forwardCost[i] + backwardCost[i]);
        }
        System.out.println(ans);
    }
    static int[] dijkstra(List<Edge>[] graph, int start) {
        PriorityQueue<Edge> pq = new PriorityQueue<>((o1, o2) -> {
            return o1.cost - o2.cost;
        });
        pq.offer(new Edge(start, 0));
        int[] cost = new int[graph.length];
        final int INF = 1000000000;
        for (int i = 1; i < cost.length; i++) {
            cost[i] = INF;
        }
        cost[start] = 0;
        while (!pq.isEmpty()) {
            Edge now = pq.poll();
            if (cost[now.dist] < now.cost) continue;
            for (Edge next : graph[now.dist]) {
                if (cost[next.dist] > cost[now.dist] + next.cost) {
                    cost[next.dist] = cost[now.dist] + next.cost;
                    pq.offer(new Edge(next.dist, cost[next.dist]));
                }
            }
        }
        return cost;
    }
}

class Edge {
    int dist, cost;

    public Edge(int dist, int cost) {
        this.dist = dist;
        this.cost = cost;
    }
}
