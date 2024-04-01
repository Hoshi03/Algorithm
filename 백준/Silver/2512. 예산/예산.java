import javax.print.DocFlavor;
import java.io.*;
import java.util.*;


public class Main {
    static long solution(long[] arr, int money){
        int n = arr.length;
        long l = arr[0];
        long r = arr[n-1];
        long ans = 0;
        while (l <= r){
            long m = (l+r)/2;
            long res = 0;
            long tmp = getCount(arr,money);

            if (res <= tmp) {
                ans = m;
                l = m+1;
            }

            else r = m-1;
        }
        return ans;
    }

    static long getCount(long[] arr, long money){
        int n = arr.length;
        long ans = 0;
        long tmpMoney = 0;

        for (int i = 0; i < n; i++){
            long maxMoney = money/(n-i); // 최대 금액값
            if (arr[i] <= maxMoney) {
                ans = arr[i];
                money -= arr[i];
            }
            else{
                ans = money / (n-i);
                break;
            }
        }

        return ans;
    }

    public static void main(String[] args) throws IOException {

       Scanner in = new Scanner(System.in);

       int n = in.nextInt();
       long[] arr= new long[n];
       for (int i = 0; i < n; i++) arr[i] = in.nextInt();
       int m = in.nextInt();
       Arrays.sort(arr);


       // System.out.println(solution(arr, m));
        System.out.println(getCount(arr,m));
    }
}