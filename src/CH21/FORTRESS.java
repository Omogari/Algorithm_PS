package CH21;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class FORTRESS {

    private int[] x;
    private int[] y;
    private int[] radius;
    private int fortresses;
    private int longest;

    public FORTRESS(int fortresses) {
        x = new int[fortresses];
        y = new int[fortresses];
        radius = new int[fortresses];
        this.fortresses = fortresses;
    }

    public class TreeNode {
        private ArrayList<TreeNode> children = new ArrayList<>();
    }

    public TreeNode getTree(int rootIdx) {
        TreeNode ret = new TreeNode();
        for (int i = 0; i < fortresses; i++) {
            if (isChild(rootIdx, i)) {
                ret.children.add(getTree(i));
            }
        }
        return ret;
    }

    public boolean encloses(int fort1, int fort2) {
        double distBetweenTwoCenters = Math.pow((x[fort1] - x[fort2]), 2) + Math.pow((y[fort1] - y[fort2]), 2);
        return radius[fort1] > radius[fort2] && distBetweenTwoCenters < Math.pow((radius[fort1] - radius[fort2]), 2);
    }

    public boolean isChild(int parent, int child) {
        if (!encloses(parent, child)) return false;
        for (int i = 0; i < fortresses; i++) {
            if (i != parent && i != child && encloses(parent, i) && encloses(i, child)) {
                return false;
            }
        }
        return true;
    }

    public int height(TreeNode root) {
        if (root.children.isEmpty()) return 0;

        int[] heights = new int[root.children.size()];
        for (int i = 0; i < heights.length; i++) {
            heights[i] = height(root.children.get(i));
        }

        // find the largest value and second largest value
        Arrays.sort(heights);
        if (heights.length >= 2)
            longest = Math.max(longest, 2 + heights[heights.length - 2] + heights[heights.length - 1]);

        return 1 + heights[heights.length - 1];
    }

    public int solve(TreeNode root) {
        longest = 0;
        int depth = height(root);

        return Math.max(longest, depth);
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
            }
            TreeNode root = fortress.getTree(0);
            System.out.println(fortress.solve(root));
        }
    }
}

