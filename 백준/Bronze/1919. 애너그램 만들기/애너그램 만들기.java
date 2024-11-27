import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int[] arr = new int[30];

        String s1,s2;
        s1 = br.readLine();
        s2 = br.readLine();

        for (char x : s1.toCharArray()){
            arr[x - 97]++;
        }

        for (char x : s2.toCharArray()){
            arr[x - 97]--;
        }

        int res = 0;

        for (int x : arr){
            res += Math.abs(x);
        }

        System.out.println(res);

    }
}