import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] argv) throws IOException {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int m = in.nextInt();

        int[] arr = new int[n+1];
        int[] sum = new int[n+1];
        int[] tmp = new int[m];

        for (int i = 1; i <= n; i++){
            arr[i] = in.nextInt();
        }

        sum[1] = arr[1];

        for (int i = 2; i <= n; i++){
            sum[i] = sum[i-1] ^ arr[i];
        }

        for (int i = 0; i < m; i++){
            int start = in.nextInt();
            int end = in.nextInt();
            tmp[i] = sum[end] ^ sum[start-1];
        }

        int res = tmp[0];

        for (int i = 1; i < m; i++){
            res = res ^ tmp[i];
        }

        System.out.println(res);
    }
}
