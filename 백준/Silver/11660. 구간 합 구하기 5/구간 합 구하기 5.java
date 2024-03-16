import java.io.*;
import java.util.*;

class Main
{
    public static void main (String[] args) throws IOException {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int tmp = m;

        int[][] arr = new int[n+1][n+1];
        int[][] sum = new int[n+1][n+1];

        int[] res = new int[m];

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                arr[i][j] = in.nextInt();
            }
        }

        for (int i = 1; i <= n; i++) {
            sum[i][1] = sum[i-1][1] + arr[i][1];
            sum[1][i] = sum[1][i-1] + arr[1][i];
        }

        for (int i = 2; i <= n; i++){
            for (int j = 2; j <= n; j++){
                sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + arr[i][j];
            }
        }

        while (m-- > 0){
            int x1 = in.nextInt();
            int y1 = in.nextInt();
            int x2 = in.nextInt();
            int y2 = in.nextInt();
            res[tmp - m-1] = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
        }

        for (int x : res) System.out.println(x);
    }
}