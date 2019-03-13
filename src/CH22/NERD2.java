package CH22;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class NERD2 {

    private TreeMap<Integer, Integer> nerds = new TreeMap<>();
    private int numOfNerds = 0;

    // check (x, y) is dominated by other points
    public boolean isDominated(int x, int y) {
        Integer key = nerds.ceilingKey(x);
        if (key != null && y < nerds.get(key))
            return true;
        else
            return false;
    }

    public void checkNerds(int x, int y) {
        if (isDominated(x, y)) {
            numOfNerds += nerds.size();
            return;
        }

        Integer key = nerds.floorKey(x);
        while (key != null) {
            if (nerds.get(key) < y) {
                nerds.remove(key);
            }else {
                break;
            }
            key = nerds.floorKey(key);
        }

        nerds.put(x, y);
        numOfNerds += nerds.size();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int loop = Integer.parseInt(br.readLine());
        while (loop-- > 0) {
            NERD2 nerd2 = new NERD2();
            int applicants = Integer.parseInt(br.readLine());

            for (int i = 0; i < applicants; i++) {
                StringTokenizer stk = new StringTokenizer(br.readLine());
                nerd2.checkNerds(Integer.parseInt(stk.nextToken()), Integer.parseInt(stk.nextToken()));
            }

            System.out.println(nerd2.numOfNerds);
        }

        br.close();
    }
}
