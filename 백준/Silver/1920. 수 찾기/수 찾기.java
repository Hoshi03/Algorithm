import java.io.*;
import java.util.*;

class Main
{
    public static void main (String[] args) throws IOException {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr= new int[n];
        for (int i = 0; i < n; i++) arr[i] = in.nextInt();
        Arrays.sort(arr);


        int m = in.nextInt();
        int[] num = new int[m];
        for (int i = 0; i < m; i++) num[i] = in.nextInt();

        int[] result = new int[m];

        for (int i = 0; i < m; i++){
            int res = num[i];
            int start = 0;
            int end = arr.length-1;
            while (start <= end){
                int pos = (start + end) / 2;
                if (arr[pos] > res)end = pos -1 ;
                else if(arr[pos] < res) start = pos + 1;
                else {
                    result[i] = 1;
                    break;
                }

            }
        }

        for (int x : result) System.out.println(x);
    }
}