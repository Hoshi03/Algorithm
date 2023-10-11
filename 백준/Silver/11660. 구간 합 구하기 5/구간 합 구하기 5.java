import java.util.*;
class Main {

    public static void main(String[] args) {
        Main T = new Main();
        Scanner in =  new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] arr = new int[n+1][n+1];
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                arr[i][j] = in.nextInt();
            }
        }
        int[] res = new int[m];
        int[][] sum = new int[n+1][n+1];

        //구간합 구하기
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + arr[i][j];
            }
        }

        // 구간합 구하기 (x1,y1) (x2,y2)가 있을때를 그림으로 그려보면 이해가 된다
        for (int i = 0; i < m; i++){
            int x1 = in.nextInt();
            int y1 = in.nextInt();
            int x2 = in.nextInt();
            int y2 = in.nextInt();
            res[i] = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
        }

        for (int x : res) System.out.println(x);
    }
}