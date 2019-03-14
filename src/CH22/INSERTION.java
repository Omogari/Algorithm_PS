package CH22;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class INSERTION {

    private int[] shifted = new int[50000];
    private int n;
    private int[] A = new int[50000];

    public class TreapNode {
        private int key;
        private double priority;
        private int size;
        private TreapNode left, right;

        public TreapNode(int key) {
            this.key = key;
            priority = Math.random();
            size = 1;
        }

        public void setLeft(TreapNode newNode) {
            left = newNode;
            calcSize();
        }

        public void setRight(TreapNode newNode) {
            right = newNode;
            calcSize();
        }

        public void calcSize() {
            size = 1;
            if (left != null) size += left.size;
            if (right != null) size += right.size;
        }
    }

    public class Pair<L, R> {

        private final L left;
        private final R right;

        public Pair(L left, R right) {
            this.left = left;
            this.right = right;
        }

        public L getLeft() {
            return left;
        }

        public R getRight() {
            return right;
        }
    }

    // split root tree to two subTrees by key
    public Pair<TreapNode, TreapNode> split(TreapNode root, int key) {
        if (root == null) return new Pair(null, null);

        // split right subTree if root is less than key
        if (root.key < key) {
            Pair<TreapNode, TreapNode> rs = split(root.right, key);
            root.setRight(rs.getLeft());
            return new Pair(root, rs.getRight());
        }

        // split left subTree if root is greater than or equal to key
        Pair<TreapNode, TreapNode> rs = split(root.left, key);
        root.setLeft(rs.getRight());
        return new Pair(rs.getLeft(), root);
    }

    // return root after inserting new node
    public TreapNode insert(TreapNode root, TreapNode node) {
        if (root == null) return node;

        if (root.priority < node.priority) {
            Pair<TreapNode, TreapNode> splitted = split(root, node.key);
            node.setLeft(splitted.getLeft());
            node.setRight(splitted.getRight());
            return node;
        } else if (node.key < root.key) {
            root.setLeft(insert(root.left, node));
        } else {
            root.setRight(insert(root.right, node));
        }
        return root;
    }

    // merge two Treaps when max(a) < min(b)
    public TreapNode merge(TreapNode a, TreapNode b) {
        if (a == null) return b;
        if (b == null) return a;
        if (a.priority < b.priority) {
            b.setLeft(merge(a, b.left));
            return b;
        }
        a.setRight(merge(a.right, b));
        return a;
    }

    public TreapNode erase(TreapNode root, int key) {
        if (root == null) return root;

        if (root.key == key) {
            TreapNode ret = merge(root.left, root.right);
            root = null; // will be erased by Garbage Collector later
            return ret;
        }
        if (key < root.key) {
            root.setLeft(erase(root.left, key));
        } else {
            root.setRight(erase(root.right, key));
        }
        return root;
    }

    // return kth node
    public TreapNode kth(TreapNode root, int k) {
        int leftSize = 0;
        if (root.left != null) leftSize = root.left.size;
        if (k <= leftSize) return kth(root.left, k);
        if (k == leftSize + 1) return root;
        return kth(root.right, k - leftSize - 1);
    }

    public int countLessThan(TreapNode root, int key) {
        if (root == null) return 0;

        if (key <= root.key) return countLessThan(root.left, key);
        int ls = (root.left != null ? root.left.size : 0);
        return ls + 1 + countLessThan(root.right, key);
    }

    // =======================================================================

    public void solve() {
        // make new Treap
        TreapNode candidates = null;
        for (int i = 0; i < n; i++) {
            candidates = insert(candidates, new TreapNode(i + 1));
        }

        // fill A[] from behind
        for (int i = n - 1; i >= 0 ; i--) {

            int larger = shifted[i];
            TreapNode k = kth(candidates, i + 1 - larger);
            A[i] = k.key;
            candidates = erase(candidates, k.key);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int loop = Integer.parseInt(br.readLine());
        while (loop-- > 0) {
            INSERTION insertion = new INSERTION();

            insertion.n = Integer.parseInt(br.readLine());
            String[] input = br.readLine().split(" ");
            for (int i = 0; i < insertion.n; i++) {
                insertion.shifted[i] = Integer.parseInt(input[i]);
            }

            insertion.solve();

            for (int i = 0; i < insertion.n; i++) {
                System.out.print(insertion.A[i] + " ");
            }
            System.out.println();
        }
    }
}
