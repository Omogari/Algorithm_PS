package CH19;

import java.util.Scanner;
import java.util.Stack;

public class BRACKETS2 {

    public String checkBrackets(Stack<Character> stack, String brackets) {
        for (int i = 0; i < brackets.length(); i++) {
            char br = brackets.charAt(i);
            if (br == '(' || br == '{' || br == '[') {
                stack.push(br);
            }else if (br == ')') {
                if (stack.size() == 0 || stack.pop() != '(') return "NO";
            }else if (br == '}') {
                if (stack.size() == 0 || stack.pop() != '{') return "NO";
            }else {
                if (stack.size() == 0 || stack.pop() != '[') return "NO";
            }
        }

        if (stack.size() != 0) return "NO";
        return "YES";
    }

    public static void main(String[] args) {
        BRACKETS2 brackets2 = new BRACKETS2();
        Scanner scan = new Scanner(System.in);

        int loop = scan.nextInt();
        while(loop-- > 0) {
            String brackets = scan.next();

            Stack<Character> stack = new Stack();
            System.out.println(brackets2.checkBrackets(stack, brackets));

        }

    }
}
