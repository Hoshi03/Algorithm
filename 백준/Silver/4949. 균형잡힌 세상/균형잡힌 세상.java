import java.util.*;
import java.io.*;

public class Main{

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);

        boolean isBalanced = true;

        while (true) {
            isBalanced = true;
            String s = in.nextLine();
            Stack<Character> st = new Stack<>();
            if (s.equals(".")) break;
            for (char x : s.toCharArray()) {
                if (x == '(' || x == '[') st.push(x);

                else if (x == ')') {
                    if (st.empty() || st.pop() != '(') {
                        isBalanced = false;
                        break;
                    }
                }

                else if (x == ']') {
                    if (st.empty() || st.pop() != '[') {
                        isBalanced = false;
                        break;
                    }
                }
            }
            if (isBalanced && st.empty()) System.out.println("yes");
            else System.out.println("no");
        }
    }
}