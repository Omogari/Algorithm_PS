package CH23;

import java.util.Scanner;

public class RUNNINGMEDIAN {

    private int input = 1983;
    private int a, b;

    public int nextInput() {
        int ret = input;
        input = (int)(((long)input * a + b) % (long)20090711);
        return ret;
    }

    public int getMedian() {

    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int loop = scan.nextInt();
        while (loop-- > 0) {
            RUNNINGMEDIAN runningmedian = new RUNNINGMEDIAN();
            int length = scan.nextInt();
            runningmedian.a = scan.nextInt();
            runningmedian.b = scan.nextInt();

            
        }
    }
}
