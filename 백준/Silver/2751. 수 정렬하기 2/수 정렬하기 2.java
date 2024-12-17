import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        Scanner in = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        int n = in.nextInt();
        int[] arr= new int[n];
        for (int i  =0; i < n; i++){
            arr[i] = in.nextInt();
        }
        Arrays.sort(arr);
        for (int x : arr) {
            sb.append(x).append('\n');
        }

        System.out.println(sb);
    }
}
