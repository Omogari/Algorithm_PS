package CH08_3;

import java.util.*;

public class SNAIL {
    private int depth;
    private int rainyDays;
    private double[][] cache;

    public double finishClimbing(int days, int climbed) {
        if (days == rainyDays) {
            if (climbed >= depth) return 1;
            return 0;
        }

        // memoization
        if (cache[days][climbed] != -1) return cache[days][climbed];

        return cache[days][climbed] = 0.25 * finishClimbing(days + 1, climbed + 1) + 0.75 * finishClimbing(days + 1, climbed + 2);
    }

    public static void main(String[] args) {
        SNAIL snail = new SNAIL();
        Scanner scan = new Scanner(System.in);

        snail.cache = new double[1000][2000];

        int loop = scan.nextInt();
        while(loop-- > 0) {
            //cache init
            for (double[] arr : snail.cache) {
                Arrays.fill(arr, -1);
            }

            snail.depth = scan.nextInt();
            snail.rainyDays = scan.nextInt();

            System.out.println(snail.finishClimbing(0, 0));

        }
    }
}
