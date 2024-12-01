import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        Scanner in = new Scanner(System.in);
        int n = Integer.parseInt(br.readLine());
        while (n --> 0){
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            int[] arr = new int[20];
            for (int i = 0; i < 20; i++) arr[i] = Integer.parseInt(st.nextToken());
            int res = 0;
            int i, j;

            for (i = 1; i < arr.length; i++){
                int tmp = arr[i];
                for (j = i - 1; j >= 0 && arr[j] > tmp; j--){
                    arr[j+1] = arr[j];
                    res++;
                }
                arr[j+1] = tmp;
            }
            System.out.println(t + " " + res);
        }
    }
}
