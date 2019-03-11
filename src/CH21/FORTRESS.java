package CH21;

import java.util.ArrayList;
import java.util.Scanner;

public class FORTRESS {

    private int[] x;
    private int[] y;
    private int[] radius;
    private int[] height; // depth of tree

    public FORTRESS(int fortresses) {
        x = new int[fortresses];
        y = new int[fortresses];
        radius = new int[fortresses];
        height = new int[fortresses];
    }

    public void countHeightOfFortress(int x, int y, int radius, int index) {
        if (index == 0) { // first fortress (root of tree)
            height[index] = 0;
            return;
        }

        int height = 0;
        for (int i = 0; i < index; i++) {
            double distBetweenTwoCenter = Math.sqrt(Math.pow((this.x[i] - x), 2) + Math.pow((this.y[i] - y), 2));
            if (distBetweenTwoCenter < this.radius[i] + radius) { // 비교대상 원 안으로 들어가는 경우 : tree의 깊이 1 증가
                height++;
            }
        }
        this.height[index] = height;

    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int loop = scan.nextInt();
        while(loop-- > 0) {
            int fortresses = scan.nextInt();

            FORTRESS fortress = new FORTRESS(fortresses);

            for (int i = 0; i < fortresses; i++) {
                fortress.x[i] = scan.nextInt();
                fortress.y[i] = scan.nextInt();
                fortress.radius[i] = scan.nextInt();

                fortress.countHeightOfFortress(fortress.x[i], fortress.y[i], fortress.radius[i], i);
            }


        }
    }

    public class TreeNode {
        private int x;
        private int y;
        private int radius;
        private ArrayList<TreeNode> children;

        public TreeNode(int x, int y, int radius) {
            this.x = x;
            this.y = y;
            this.radius = radius;
            children = new ArrayList<>();
        }

        

        public boolean setTreeNode(TreeNode tn) {
            double distBetweenTwoCenter = Math.sqrt(Math.pow((x - tn.x), 2) + Math.pow((y - tn.y), 2));
            if (distBetweenTwoCenter < radius + tn.radius) { // 비교대상 원 안으로 들어가는 경우 : tree의 깊이 1 증가

            }
        }
    }
}

