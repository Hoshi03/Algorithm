import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class Main {

    public static void solution(int[] arr, int sol) throws IOException {


    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[] arr= new int[n];
        String s = br.readLine();
        String[] num = s.split(" ");
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(num[i]);
        int sol = Integer.parseInt(br.readLine());

        Arrays.sort(arr);

        int lt = 0;
        int rt = arr.length-1;
        int res = 0;

        while (lt < rt){
            if (arr[lt] + arr[rt] == sol) {
                res++;
                lt++;
                rt--;
            }
            else if (arr[lt] + arr[rt] < sol) {
                lt++;
            }

            else if (arr[lt] + arr[rt] > sol){
                rt --;
            }
        }

        System.out.println(res);
    }
}