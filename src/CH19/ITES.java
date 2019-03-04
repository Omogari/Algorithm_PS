package CH19;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class ITES {


    private long lastSignal = 1983;

    public void setLastSignal(long lastSignal) {
        this.lastSignal = lastSignal;
    }

    public int signal() {
        int ret = (int)(lastSignal % 10000) + 1;
        lastSignal = (lastSignal * 214013 + 2531011) % (long) Math.pow(2, 32);
        return ret;
    }

    public int countTargetSum(int targetSum, int to) {
        Queue<Integer> queue = new LinkedList<>();
        int sumOfQueue = 0;
        int count = 0;
        int indexOfSignal = 0;

        while(indexOfSignal < to) {
            if (sumOfQueue == targetSum) {
                count++;
                sumOfQueue -= queue.poll();
            } else if (sumOfQueue > targetSum) {
                sumOfQueue -= queue.poll();
            } else {
                int sign = signal();
                queue.offer(sign);
                sumOfQueue += sign;
                indexOfSignal++;
            }
        }

        return count;
    }

    public static void main(String[] args) {
        ITES ites = new ITES();
        Scanner scan = new Scanner(System.in);

        int loop = scan.nextInt();
        while(loop-- > 0) {
            int targetSum = scan.nextInt();
            int to = scan.nextInt();

            System.out.println(ites.countTargetSum(targetSum, to));
            ites.setLastSignal(1983);
        }
    }
}
