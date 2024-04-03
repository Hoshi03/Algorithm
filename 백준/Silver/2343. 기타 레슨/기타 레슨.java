import java.io.*;
import java.util.*;


public class Main {

    static int parametric_search(int[] arr, int count){
        int l = 0;
        int n = arr.length;
        int r = 10000 * n;
        int res = -1;

        while (l <= r){
            int m = (l+r) / 2;

            if (isAble(arr, m, count)){
                res = m;
                r = m-1;
            }

            else l = m+1;
        }
        return res;
    }

    static boolean isAble(int[] arr, int maxLen, int count){
        int tmp = maxLen;
        int cnt = 1;
        for (int x : arr){
            if (maxLen < x) return false;
            if (tmp < x){
                tmp = maxLen;
                cnt++;
            }
            tmp -= x;
        }

        return cnt <= count;
    }


    public static void main(String[] args) throws IOException {

       Scanner in = new Scanner(System.in);
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = in.nextInt();
        int m = in.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = in.nextInt();

        System.out.print(parametric_search(arr, m));
    }
}