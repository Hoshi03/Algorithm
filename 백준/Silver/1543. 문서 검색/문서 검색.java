import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String s = br.readLine();
        String target = br.readLine();
        int res = 0;
        if (s.length() < target.length()) res = 0;
        else {
            while (s.contains(target)){
                res++;
                s = s.substring(s.indexOf(target)+target.length());

            }
        }
        System.out.println(res);
    }
}