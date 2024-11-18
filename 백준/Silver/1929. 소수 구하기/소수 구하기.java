import java.io.*;
import java.util.*;



public class Main {

    static boolean isSosu(int x){
        if (x == 1) return false;
        if (x == 2) return true;
        for(int i = 2; i <= Math.sqrt(x); i++){
            if (x % i == 0) return false;
        }

        return true;
    }


    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for (int i = n; i <= m; i++) if (isSosu(i)) bw.write(String.valueOf(i) + '\n');
        bw.flush();
    }

}