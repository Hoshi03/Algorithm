import java.util.*;
import java.io.*;


class Main
{
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        Deque<Character> deque = new ArrayDeque<>();

        // (는 스택에 넣기
        // )를 만났을때 이전께 (면 레이저, )면 pop하고 갯수세기

        int res = 0;

        char[] arr = in.nextLine().toCharArray();
        char past = ' ';
        for (int i = 0; i < arr.length; i++){
            char tmp = arr[i];
            if (tmp == '('){
                deque.addFirst(tmp);
                past = '(';
            }

            else if (tmp == ')') {
                //레이저를 만남
                if (past == '('){
                    deque.removeFirst();
                    res += deque.size();
                }
                // 막대기 하나 끝
                else {
                    deque.removeFirst();
                    res += 1;
                }
                past = ')';
            }
        }
        System.out.println(res);
    }
}