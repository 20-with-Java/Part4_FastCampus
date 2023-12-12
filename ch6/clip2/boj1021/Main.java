import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); int m = sc.nextInt();
        int[] arr = new int[m];
        for(int i = 0; i < m; i++) {
            arr[i] = sc.nextInt();
        }
        Queue<Integer> q = new LinkedList<>();
        for(int i = 1; i <= n; i++) {
            q.offer(i);
        }
        int answer = 0;
        for(int i = 0; i < m; i++) {
            int cnt = 0;
            while(q.peek() != arr[i]) {
                q.offer(q.poll());
                cnt++;
            }
            answer += Math.min(Math.abs(q.size() - cnt), cnt);
            q.poll();
        }
        System.out.println(answer);
    }
}
