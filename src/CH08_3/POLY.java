package CH08_3;

import java.util.*;

public class POLY {
    private static final int MOD = 10 * 1000 * 1000;
    private int[][] cache;

    public int countMonoPoly(int squares, int firstLine) {
        // base case
        if (squares == firstLine) return 1;

        // memoization
        if (cache[squares][firstLine] != -1) return cache[squares][firstLine];

        int ret = 0;
        for (int i = 1; i <= squares - firstLine; i++) {
            ret += (firstLine + i - 1) * countMonoPoly(squares - firstLine, i) % MOD;
        }
        return cache[squares][firstLine] = ret % MOD;
    }

    public static void main(String[] args) {
        POLY poly = new POLY();
        Scanner scan = new Scanner(System.in);

        poly.cache = new int[101][101];

        int loop = scan.nextInt();
        while(loop-- > 0) {
            // cache init
            for (int[] arr : poly.cache) {
                Arrays.fill(arr, -1);
            }

            int n = scan.nextInt();

            int polyomino = 0;
            for (int i = 1; i <= n; i++) {
                polyomino += poly.countMonoPoly(n, i);
            }
            System.out.println(polyomino % MOD);
        }
    }
}
