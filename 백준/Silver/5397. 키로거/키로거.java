import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());

        while (n --> 0){
           Deque<Character> forward = new ArrayDeque<>();
           Deque<Character> backward = new ArrayDeque<>();
           char[] arr = br.readLine().toCharArray();
           for (char x : arr){
               if (x == '-'){
                   if (!forward.isEmpty()) forward.pop();
               }
               else if (x == '<') {
                   if (!forward.isEmpty()) backward.push(forward.pop());
               } else if (x == '>') {
                   if (!backward.isEmpty()) forward.push(backward.pop());
               }
               else forward.push(x);
           }

           StringBuilder sb = new StringBuilder();
           while (!forward.isEmpty()) sb.append(forward.pollLast());
           while (!backward.isEmpty()) sb.append(backward.pollFirst());
           bw.write(sb+"\n");
        }
        bw.flush();
    }
}