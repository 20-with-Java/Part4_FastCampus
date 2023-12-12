import java.util.PriorityQueue;
import java.util.Scanner;

public class Main2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        StringBuilder ans = new StringBuilder();

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        while (n-- > 0) {
            int x = sc.nextInt();
            if (x == 0) {
                if(pq.isEmpty())
                    ans.append(0).append('\n');
                else
                    ans.append(pq.poll()).append('\n');
            }
            else pq.offer(x);
        }
        System.out.println(ans);
    }
}
