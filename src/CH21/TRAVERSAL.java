package CH21;

import java.util.ArrayList;
import java.util.Scanner;

public class TRAVERSAL {

    private int[] preorder;
    private int[] inorder;
    private ArrayList<Integer> postorder;

    public void generatePostorder(int preFrom, int preTo, int inFrom, int inTo){ //int[] preorder, int[] inorder) {
        int root = preorder[preFrom];

        // find root node index in inorder traversal
        int rootIdx = -1;
        for (int i = inFrom; i < inTo; i++) {
            if (inorder[i] == root) {
                rootIdx = i;
                break;
            }
        }
        // next subPreorder in left Tree : preFrom + 1 ~ rootIdx + 1
        // next subInorder in left Tree : preFrom ~ rootIdx
        // next subPreorder in right Tree : rootIdx + 1 ~ preTo
        // next subInorder in right Tree : rootIdx + 1 ~  ~ inTo

//        1
//        7
//        27 16 9 12 54 36 72
//        9 12 16 27 36 54 72

        // 12 9 16

        // gen(0, 7, 0, 7)
        // root : 27, rootIdx : 3
            // gen(1, 4, 0, 3)
            // root : 16, rootIdx : 2
                // gen(2, 4, 0, 2)
                // root : 9, rootIdx : 0 => pass
                // pass
            // gen(4, 7, 4, 7)
            // root : 54, rootIdx : 5
                // gen(5, 9)

        // length
        int sizeOfLTree = rootIdx - preFrom;

        // left subTree
        if (preFrom == rootIdx) {
            postorder.add(preorder[preFrom]); // leaf node
            //return;
        }else if (preFrom < rootIdx) {
            generatePostorder(preFrom + 1, preFrom + rootIdx, inFrom, rootIdx);
        }

        // right subTree
        if (rootIdx + 1 == inTo - 1) {
            postorder.add(inorder[rootIdx + 1]); // leaf node
            //return;
        }else if (rootIdx + 1 < inTo - 1) {
            generatePostorder(rootIdx + 1, preTo, rootIdx + 1, inTo);
        }

        postorder.add(root);

    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int loop = scan.nextInt();
        while(loop-- > 0) {
            TRAVERSAL traversal = new TRAVERSAL();

            // init traversals
            int nodes = scan.nextInt();
            traversal.preorder = new int[nodes];
            traversal.inorder = new int[nodes];
            traversal.postorder = new ArrayList<>();

            for (int i=0; i<nodes; i++) {
                traversal.preorder[i] = scan.nextInt();
            }
            for (int i=0; i<nodes; i++) {
                traversal.inorder[i] = scan.nextInt();
            }

            traversal.generatePostorder(0, nodes, 0, nodes);
            for (int node : traversal.postorder){
                System.out.println(node + " ");
            }
        }
    }
}
