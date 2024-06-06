import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Deque<Integer> stack = new ArrayDeque<>();
        StringBuilder res = new StringBuilder();
        int cnt = 1;
        while (n--> 0){
            int target = in.nextInt();
            while (cnt <= target ) {
                stack.push(cnt++);
                res.append("+\n");
            }

            if (stack.isEmpty() || stack.peek() != target) {
                System.out.println("NO");
                return;
            }
            
            else {
                stack.pop();
                res.append("-\n");
            }

        }
        System.out.println(res);
    }
}