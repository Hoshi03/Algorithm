import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        Deque<Character> deque = new ArrayDeque<>();
        int res = 0, tmp = 1;
        boolean isEmpty = false;

        char[] arr = in.nextLine().toCharArray();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == '(' || arr[i] == '[') {
                deque.addLast(arr[i]);
                if (arr[i] == '(') {
                    tmp *= 2;
                } else {
                    tmp *= 3;
                }
            } else if (arr[i] == ')') {
                if (deque.isEmpty() || deque.getLast() != '(') {
                    isEmpty = true;
                    break;
                }
                if (arr[i-1] == '(') res += tmp;
                deque.removeLast();
                tmp /= 2;
            } else if (arr[i] == ']') {
                if (deque.isEmpty() || deque.getLast() != '[') {
                    isEmpty = true;
                    break;
                }
                if (arr[i-1] == '[') res += tmp;
                deque.removeLast();
                tmp /= 3;
            }
        }

        if (!deque.isEmpty() || isEmpty) System.out.println(0);
        else System.out.println(res);
    }
}