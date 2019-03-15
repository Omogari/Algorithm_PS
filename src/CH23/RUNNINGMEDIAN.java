package CH23;

import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class RUNNINGMEDIAN {

    private int input = 1983;
    private int a, b;

    public int nextInput() {
        int ret = input;
        input = (int)(((long)input * a + b) % (long)20090711);
        return ret;
    }

    public int getSumOfMedian(int length) {
        int sumOfMedian = 0;

        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for (int i = 0; i < length; i++) {
            int input = nextInput();

            // if length is odd, offer one more node to maxHeap
            if (maxHeap.size() == minHeap.size()) {
                maxHeap.offer(input);
            }else {
                minHeap.offer(input);
            }

            // maximum of maxHeap <= mininum of minHeap
            if (!maxHeap.isEmpty() && !minHeap.isEmpty() && maxHeap.peek() > minHeap.peek()) {
                int maxH = maxHeap.poll();
                int minH = minHeap.poll();
                maxHeap.offer(minH);
                minHeap.offer(maxH);
            }

            sumOfMedian = (sumOfMedian + maxHeap.peek()) % 20090711;
        }

        return sumOfMedian;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int loop = scan.nextInt();
        while (loop-- > 0) {
            RUNNINGMEDIAN runningmedian = new RUNNINGMEDIAN();
            int length = scan.nextInt();
            runningmedian.a = scan.nextInt();
            runningmedian.b = scan.nextInt();

            System.out.println(runningmedian.getSumOfMedian(length));
        }
    }
}
