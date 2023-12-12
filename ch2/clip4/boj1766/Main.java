import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        int indegree[] = new int[n + 1];
        List<Integer>[] list = new ArrayList[n + 1];
        for(int i = 1; i <= n; i++) {
            list[i] = new ArrayList<>();
        }
        for(int i = 0; i < m; i++) {
            int a = sc.nextInt(), b = sc.nextInt();
            list[a].add(b);
            indegree[b]++;
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i = 1; i <= n; i++) {
            if(indegree[i] == 0) pq.offer(i);
        }
        while(!pq.isEmpty()) {
            int now = pq.poll();
            System.out.print(now + " ");
            for(int next : list[now]) {
                indegree[next]--;
                if(indegree[next] == 0) pq.offer(next);
            }
        }
    }
}
