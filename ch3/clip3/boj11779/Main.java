import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        final int INF = 1000000000;
        int n = sc.nextInt(), m = sc.nextInt();
        List<Edge>[] graph = new List[n + 1];
        int[] cost = new int[n + 1];
        int[] path = new int[n + 1];
        for(int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
            cost[i] = INF;
        }
        for(int i = 0; i < m; i++) {
            int s = sc.nextInt(), d = sc.nextInt(), c = sc.nextInt();
            graph[s].add(new Edge(d, c));
        }
        int start = sc.nextInt(), end = sc.nextInt();
        PriorityQueue<Edge> pq = new PriorityQueue<>((o1, o2) -> {
            return o1.cost - o2.cost;
        });
        pq.offer(new Edge(start, 0));
        cost[start] = 0;

        while(!pq.isEmpty()) {
            Edge now = pq.poll();
            if(cost[now.dist] < now.cost) continue;
            for(Edge next : graph[now.dist]) {
                if(cost[now.dist] + next.cost < cost[next.dist]) {
                    cost[next.dist] = cost[now.dist] + next.cost;
                    pq.offer(new Edge(next.dist, cost[next.dist]));
                    path[next.dist] = now.dist;
                }
            }
        }
        System.out.println(cost[end]);
        Stack<Integer> stack = new Stack<>();
        int now = end;
        while(now != 0) {
            stack.push(now);
            now = path[now];
        }
        System.out.println(stack.size());
        while(!stack.isEmpty()) {
            System.out.print(stack.pop() + " ");
        }
    }

}

class Edge {
    int dist, cost;
    public Edge(int dist, int cost) {
        this.dist = dist;
        this.cost = cost;
    }
}
