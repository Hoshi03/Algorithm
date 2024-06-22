import java.io.*;
import java.util.*;

public class Main {

    static int n, m;
    static boolean[] visited = new boolean[10001];
    static int[] arr;
    static int[] res;

    static void dfs(int count){
        if (count >= m){
            StringBuilder sb = new StringBuilder();
            for (int x : res) sb.append(x).append(" ");
            System.out.println(sb);
            return;
        }

        for (int x : arr){
            if (!visited[x]){
                visited[x] = true;
                res[count] = x;
                dfs(count + 1);
                visited[x] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        arr = new int[n];
        res = new int[m];
        for (int i = 0; i < n; i++) arr[i] = in.nextInt();
        Arrays.sort(arr);
        dfs(0);
    }
}
