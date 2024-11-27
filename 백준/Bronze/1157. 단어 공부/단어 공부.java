import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String s = br.readLine().toUpperCase();
        int[] arr = new int[30];
        for (char x : s.toCharArray()){
            arr[x-65]++;
        }

//        for (int x : arr) System.out.print(x + " ");;


        int res = -1, cnt = 0, idx = 0;

        for (int i = 0; i < arr.length; i++){
            if (res < arr[i]){
                res = arr[i];
                idx = i;
            }
        }

        for (int x : arr) if (x == res) cnt++;

        if (cnt > 1) System.out.println('?');
        else System.out.println((char) (idx + 65));
    }
}