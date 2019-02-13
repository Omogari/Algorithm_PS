package CH08_3;

import java.util.*;

public class ASYMTILING {
    private int n;
    private int[] cache;
    private static final int MOD = 1000000007;

    public int asymmetric(int length) {
        if (length % 2 == 1) return (tiling(length) - tiling(length / 2) + MOD) % MOD;
        int ret = tiling(length);
        ret = (ret - tiling(length / 2) + MOD ) % MOD;
        ret = (ret - tiling(length / 2 - 1) + MOD) % MOD;
        return ret;
    }

    public int tiling(int length) {
        // base case
        if (length <= 1) return 1;

        // memoization
        if (cache[length] != -1) return cache[length];

        return cache[length] = (tiling(length - 1) + tiling(length - 2)) % MOD;
    }

    public static void main(String[] args) {
        ASYMTILING asymtiling = new ASYMTILING();
        Scanner scan = new Scanner(System.in);
        asymtiling.cache = new int[101];

        int loop = scan.nextInt();
        while (loop-- > 0) {
            asymtiling.n = scan.nextInt();

            //cache init
            Arrays.fill(asymtiling.cache, -1);

            System.out.println(asymtiling.asymmetric(asymtiling.n));
        }

    }
}
