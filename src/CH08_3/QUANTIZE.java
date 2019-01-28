package CH08_3;

import java.util.Scanner;

public class QUANTIZE {

    public static int[] quanArr;
    public static int s;

    public void quantize(int start){

    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int loop = scan.nextInt();

        while(loop-- > 0){
            int n;
            n = scan.nextInt();
            s = scan.nextInt();
            quanArr = new int[n];
            for (int i = 0; i < n; i++) {
                quanArr[i] = scan.nextInt();
            }


        }
    }
}
