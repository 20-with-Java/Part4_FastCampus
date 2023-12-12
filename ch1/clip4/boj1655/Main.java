import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        PriorityQueue<Integer> small = new PriorityQueue<>((o1, o2) -> {
            return o1 < o2 ? 1 : -1;
        });
        PriorityQueue<Integer> big = new PriorityQueue<>();
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; i++) {
            int num = sc.nextInt();
            if (small.size() == big.size()) small.offer(num);
            else big.offer(num);

            if (!small.isEmpty() && !big.isEmpty()) {
                int s = small.peek();
                int b = big.peek();
                if (s > b) {
                    small.poll();
                    big.poll();
                    small.offer(b);
                    big.offer(s);
                }
            }
            ans.append(small.peek()).append('\n');
        }
        System.out.println(ans);
    }
}
