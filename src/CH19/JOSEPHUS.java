package CH19;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class JOSEPHUS {

    public ArrayList<Integer> toSurvive(ArrayList<Integer> list, int order) {
        int i = 0;
        int count = 0;
        while(list.size() > 2) {
            if (count % order == 0) list.remove(i--);
            i++;
            count++;
            if (i == list.size()) i = 0;
        }

        return list;
    }

    public static void main(String[] args) {
        JOSEPHUS josephus = new JOSEPHUS();
        Scanner scan = new Scanner(System.in);

        int loop = scan.nextInt();
        while (loop-- > 0) {
            int soldiers = scan.nextInt();
            int order = scan.nextInt();

            ArrayList<Integer> list = new ArrayList<>();

            // list setting
            for (int i = 0; i < soldiers; i++) {
                list.add(i + 1);
            }

            for (int survivor : josephus.toSurvive(list, order)) {
                System.out.print(survivor + " ");
            }
            System.out.println();
        }

    }
}
