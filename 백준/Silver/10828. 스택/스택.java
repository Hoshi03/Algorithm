import java.util.*;
import java.io.*;

public class Main{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        Stack<String> st = new Stack<>();
        while (n --> 0){
            String[] s = br.readLine().split(" ");
            if (s[0].equals("push")) st.push(s[1]);
            else if (s[0].equals("pop")){
                if (st.empty()) bw.write("-1\n");
                else bw.write(st.pop() +"\n");
            }
            else if (s[0].equals("size")) bw.write(st.size()+"\n");
            else if (s[0].equals("empty")) {
                if (st.empty()) bw.write("1\n");
                else bw.write("0\n");
            }

            else if (s[0].equals("top")) {
                if (st.empty()) bw.write("-1\n");
                else bw.write(st.peek() + "\n");
            }
        }

        bw.flush();
    }
}