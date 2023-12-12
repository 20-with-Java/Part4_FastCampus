import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        List<String> s = new ArrayList<>();
        List<String> p = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            s.add(sc.next());
        }
        for (int i = 0; i < m; i++) {
            p.add(sc.next());
        }
        s.sort(String::compareTo);
        int cnt = 0;
        for (String str : p) {
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                String target = s.get(mid).substring(0, str.length());
                int compare = target.compareTo(str);
                if (compare == 0){
                    cnt++;
                    break;
                }
                else if (compare < 0) left = mid + 1;
                else right = mid - 1;
            }
        }
        System.out.println(cnt);

    }
}
