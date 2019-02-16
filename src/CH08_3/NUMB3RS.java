package CH08_3;

import java.util.*;

public class NUMB3RS {

    private int[][] villageArr;
    private double[][] cache;
    private int[] roadsOnVillage;
    private int prison; // position of prison
    private int villages; // num of villages

    public double probCatchDunibal(int days, int village) {
        // base case
        if (days == 1) {
            if (villageArr[prison][village] == 0) return 0;
            return 1.0 / roadsOnVillage[prison];
        }

        // memoization
        if (cache[days][village] != -1) return cache[days][village];

        double ret = 0;
        for (int i = 0; i < villages; i++) {
            if (villageArr[village][i] == 1)
                ret += (1.0 / roadsOnVillage[i]) * probCatchDunibal(days - 1, i);
        }

        return cache[days][village] = ret;
    }

    public static void main(String[] args) {
        NUMB3RS numb3RS = new NUMB3RS();
        Scanner scan = new Scanner(System.in);

        numb3RS.villageArr = new int[51][51];
        numb3RS.cache = new double[101][51];
        numb3RS.roadsOnVillage = new int[51];

        int loop = scan.nextInt();
        while(loop-- > 0) {
            // cache init
            for(double[] arr : numb3RS.cache) {
                Arrays.fill(arr, -1);
            }
            Arrays.fill(numb3RS.roadsOnVillage, 0);

            numb3RS.villages = scan.nextInt();
            int days = scan.nextInt();
            numb3RS.prison = scan.nextInt();
            for (int i = 0; i < numb3RS.villages; i++) {
                for (int j = 0; j < numb3RS.villages; j++) {
                    int temp = scan.nextInt();
                    numb3RS.villageArr[i][j] = temp;
                    numb3RS.roadsOnVillage[i] += temp;
                }
            }

            int targets = scan.nextInt();
            int[] target = new int[targets];
            for (int i = 0; i < targets; i++) {
                target[i] = scan.nextInt();
            }

            for(int village : target) {
                System.out.println(numb3RS.probCatchDunibal(days, village));
            }


        }
    }
}
