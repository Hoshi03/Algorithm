import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(st.nextToken());
        int b =  Integer.parseInt(st.nextToken());
        while (n != 0){
            int tmp = n % b;
            if (tmp >= 10){
                tmp += 55;
                sb.append(Character.toChars(tmp));
            }

            else sb.append(String.valueOf(tmp));
            n /= b;
        }
        System.out.println(sb.reverse());
    }
}
