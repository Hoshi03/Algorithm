import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class Main {

    public static void solution(int[] arr) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] res = new int[10001];

        for (int i =0; i < arr.length; i++){
            res[arr[i]]++;
        }

        for (int i = 1; i < res.length; i++) {
            while (res[i]-- > 0){
                bw.write(i + "\n");
            }
        }
        bw.flush();
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[] arr= new int[n];
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(br.readLine());
        solution(arr);
    }
}