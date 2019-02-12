package CH08_3;

import java.util.*;

public class TILING2 {

    private int n;
    private int[] cache = new int[101];

    public int countTiling(int remainingLen){

        //memoization
        if(cache[remainingLen] != -1) return cache[remainingLen];

        //base case
        if(remainingLen <= 1) return cache[remainingLen] = 1;

        return cache[remainingLen] = (countTiling(remainingLen - 1) + countTiling(remainingLen - 2)) % 1000000007;
    }

    public static void main(String[] args) {
        TILING2 tiling2 = new TILING2();

        Scanner scan = new Scanner(System.in);

        int loop = scan.nextInt();

        while(loop-- > 0){
            tiling2.n = scan.nextInt();

            //cache init
            Arrays.fill(tiling2.cache, -1);

            System.out.println(tiling2.countTiling(tiling2.n));
        }
    }
}
