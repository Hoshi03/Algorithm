import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int cnt = 666;
        int res = 0;
        while (true) {
            if (Integer.toString(cnt).contains("666")) res++;
            if (res == n) break;
            cnt++;
        }
        System.out.println(cnt);
    }
}