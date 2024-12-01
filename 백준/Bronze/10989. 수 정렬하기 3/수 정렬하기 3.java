import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        Scanner in = new Scanner(System.in);
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n ; i++) arr[i] = Integer.parseInt(br.readLine());
        Arrays.sort(arr);
        for (int i = 0; i < n; i++) sb.append(arr[i]).append('\n');
        System.out.println(sb);
    }
}
