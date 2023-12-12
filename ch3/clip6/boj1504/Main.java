import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static final int INF = 1000000000;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), e = sc.nextInt();
        if(e == 0) {
            System.out.println(-1);
            return;
        }
        List<Edge> graph[] = new ArrayList[n + 1];
        int[] cost = new int[n + 1];
        PriorityQueue<Edge> pq = new PriorityQueue<>((o1, o2) -> {
            return o1.cost - o2.cost;
        });
        for(int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
            cost[i] = INF;
        }
        for(int i = 0; i < e; i++) {
            int s = sc.nextInt(), d = sc.nextInt(), c = sc.nextInt();
            graph[s].add(new Edge(d, c));
            graph[d].add(new Edge(s, c));
        }
        int v1 = sc.nextInt(), v2 = sc.nextInt();
        // 1 -> v1 -> v2 -> n
        int answer1 = dijkstra(graph, 1, v1) + dijkstra(graph, v1, v2) + dijkstra(graph, v2, n);
        // 1 -> v2 -> v1 -> n
        int answer2 = dijkstra(graph, 1, v2) + dijkstra(graph, v2, v1) + dijkstra(graph, v1, n);
        int answer = Math.min(answer1, answer2);
        if(answer >= INF) System.out.println(-1);
        else System.out.println(answer);
    }
    static int dijkstra(List<Edge>[] graph, int start, int end) {
        int[] cost = new int[graph.length];
        PriorityQueue<Edge> pq = new PriorityQueue<>((o1, o2) -> {
            return o1.cost - o2.cost;
        });
        pq.offer(new Edge(start, 0));
        for(int i = 1; i < cost.length; i++) {
            cost[i] = INF;
        }
        cost[start] = 0;

        while(!pq.isEmpty()) {
            Edge now = pq.poll();
            if(cost[now.dist] < now.cost) continue;
            for(Edge next : graph[now.dist]) {
                if(cost[next.dist] > cost[now.dist] + next.cost) {
                    cost[next.dist] = cost[now.dist] + next.cost;
                    pq.offer(new Edge(next.dist, cost[next.dist]));
                }
            }
        }
        return cost[end];
    }
}

class Edge {
    int dist, cost;

    public Edge(int dist, int cost) {
        this.dist = dist;
        this.cost = cost;
    }
}