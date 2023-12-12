import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Meeting> meeting = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            meeting.add(new Meeting(sc.nextInt(), sc.nextInt()));
        }
        meeting.sort((o1, o2) -> {
            if (o1.start == o2.start) return o1.end - o2.end;
            return o1.start - o2.start;
        });
        PriorityQueue<Meeting> pq = new PriorityQueue<>((o1, o2) -> {
            return o1.end - o2.end;
        });
        int ans = 1;
        for (Meeting m : meeting) {
            if (pq.isEmpty()) {
                pq.offer(m);
                continue;
            }
            while (!pq.isEmpty() && pq.peek().end <= m.start) pq.poll();
            pq.offer(m);
            ans = Math.max(ans, pq.size());
        }
        System.out.println(ans);
    }
}

class Meeting {
    int start;
    int end;

    public Meeting(int start, int end) {
        this.start = start;
        this.end = end;
    }
}