package CH08_3;

import java.util.*;

public class TRIPATHCNT {

    private int[][] numTriangle;
    private int[][] maxPathCache;
    private int[][] cache;
    private int n;

    public int maxTriPath(int row, int col) {
        if (row >= n) return 0;

        // memoization
        if (maxPathCache[row][col] != -1) return maxPathCache[row][col];

        int ret = numTriangle[row][col];
        ret += Math.max(maxTriPath(row + 1, col), maxTriPath(row + 1, col + 1));

        maxPathCache[row][col] = ret;

        return ret;
    }

    public int countMaxTriPath(int row, int col) {

        if (row == n - 1) return 1;

        // memoization
        if (cache[row][col] != -1) return cache[row][col];

        int leftPath = maxPathCache[row + 1][col];
        int rightPath = maxPathCache[row + 1][col + 1];

        int ret = 0;

        int leftCount = countMaxTriPath(row + 1, col);
        int rightCount = countMaxTriPath(row + 1, col + 1);

        if (leftPath == rightPath) {
            ret = leftCount + rightCount;
        }else if (leftPath > rightPath) {
            ret = leftCount;
        }else {
            ret = rightCount;
        }

        cache[row][col] = ret;

        return ret;
    }

    public static void main(String[] args) {
        TRIPATHCNT tripathcnt = new TRIPATHCNT();
        Scanner scan = new Scanner(System.in);

        tripathcnt.numTriangle = new int[100][100];
        tripathcnt.maxPathCache = new int[100][100];
        tripathcnt.cache = new int[100][100];

        int loop = scan.nextInt();
        while(loop-- > 0) {
            // arr init
            for (int[] arr : tripathcnt.numTriangle) {
                Arrays.fill(arr, -1);
            }
            for (int[] arr : tripathcnt.maxPathCache) {
                Arrays.fill(arr, -1);
            }
            for (int[] arr : tripathcnt.cache) {
                Arrays.fill(arr, -1);
            }

            tripathcnt.n = scan.nextInt();
            for (int i = 0; i < tripathcnt.n; i++) {
                for (int j = 0; j <= i; j++) {
                    tripathcnt.numTriangle[i][j] = scan.nextInt();
                }
            }
            tripathcnt.maxTriPath(0, 0);
            System.out.println(tripathcnt.countMaxTriPath(0, 0));
        }

    }
}
