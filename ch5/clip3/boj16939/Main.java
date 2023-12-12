import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] area = new int[25];
        for (int i = 1; i <= 24; i++) {
            area[i] = sc.nextInt();
        }

        Cube cube = new Cube(area);

        cube.r();
        exitIfTrue(cube.check());
        cube.r();
        cube.r();
        exitIfTrue(cube.check());
        cube.r();

        cube.u();
        exitIfTrue(cube.check());
        cube.u();
        cube.u();
        exitIfTrue(cube.check());
        cube.u();

        cube.f();
        exitIfTrue(cube.check());
        cube.f();
        cube.f();
        exitIfTrue(cube.check());

        System.out.println(0);
    }
    static void exitIfTrue(boolean b) {
        if(b) {
            System.out.println(1);
            System.exit(0);
        }
    }
}

class Cube {
    int[] area;
    Cube (int[] area) {
        this.area = area;
    }
    boolean check() {
        for(int i = 1; i <= 24; i++) {
            int[] base = {1, 5, 9, 13, 17, 21};
            if(area[i] != area[base[(i - 1) / 4]]) return false;
        }
        return true;
    }
    void r() {
        int temp1 = area[2];
        int temp2 = area[4];
        area[2] = area[6];
        area[4] = area[8];
        area[6] = area[10];
        area[8] = area[12];
        area[10] = area[23];
        area[12] = area[21];
        area[23] = temp1;
        area[21] = temp2;
    }
    void u() {
        int temp1 = area[5];
        int temp2 = area[6];
        area[5] = area[13];
        area[6] = area[14];
        area[13] = area[21];
        area[14] = area[22];
        area[21] = area[17];
        area[22] = area[18];
        area[17] = temp1;
        area[18] = temp2;
    }
    void f() {
        int temp1 = area[3];
        int temp2 = area[4];
        area[3] = area[16];
        area[4] = area[14];
        area[16] = area[10];
        area[14] = area[9];
        area[10] = area[17];
        area[9] = area[19];
        area[17] = temp1;
        area[19] = temp2;
    }

}