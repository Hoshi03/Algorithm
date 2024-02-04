import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class Main {

    public static int solution(char[][] arr )  {
        int res = 0;
        int n = arr.length;

        for (int i =0; i < n; i++){
            for (int j =0; j < n; j++){
                if (j+1 < n && arr[i][j] != arr[i][j+1]){
                    swap(arr,i,j,i,j+1);
                    res = Math.max(res, Math.max(findMaxCol(arr), findMaxLow(arr)));
                    swap(arr,i,j,i,j+1);
                }

                if (i+1 < n && arr[i][j] != arr[i+1][j]){
                    swap(arr,i,j,i+1,j);
                    res = Math.max(res, Math.max(findMaxCol(arr), findMaxLow(arr)));
                    swap(arr,i,j,i+1,j);
                }
            }
        }

        return res;
    }

    public static void swap(char[][] arr, int x1, int y1, int x2, int y2){
        char tmp = arr[x1][y1];
        arr[x1][y1] = arr[x2][y2];
        arr[x2][y2] = tmp;
    }

    public static int findMaxLow(char[][] arr){
        int max = 0;

        for (int i =0; i < arr.length; i++){
            int cnt = 1;
            for (int j = 1; j < arr.length; j++){
                if (arr[i][j] == arr[i][j-1]) cnt++;

                else {
                    if (max < cnt) max = cnt;
                    cnt = 1;
                }
            }
            max = Math.max(max,cnt);
        }
        return max;
    }

    public static int findMaxCol(char[][] arr){
        int max = 0;

        for (int i =0; i < arr.length; i++){
            int cnt = 1;
            for (int j = 1; j < arr.length; j++){
                if (arr[j][i] == arr[j-1][i]) cnt++;

                else {
                    if (max < cnt) max = cnt;
                    cnt = 1;
                }
            }
            max = Math.max(max,cnt);
        }
        return max;

    }

    public static void main(String[] args) throws IOException {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();
        char[][] arr = new char[n][n];
        for (int i =0; i < n;i++){
            String s = in.nextLine();
            for (int j = 0; j < n; j++){
                arr[i][j] = s.charAt(j);
            }
        }

        System.out.println(solution(arr));

    }
}