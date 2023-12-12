import java.util.PriorityQueue;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> {
            return o1 > o2 ? 1 : -1;
        });
        for (int i = 0; i < n; i++) pq.offer(sc.nextInt());
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pq.poll();
                pq.offer(sc.nextInt());
            }
        }
        System.out.println(pq.poll());
    }
}