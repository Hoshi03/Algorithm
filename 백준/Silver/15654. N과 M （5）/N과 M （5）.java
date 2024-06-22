import java.io.*;
import java.util.*;

public class Main {

    static int n, m;
    static boolean[] visited = new boolean[10001];
    static int[] arr;
    static int[] res;

    static void dfs(int m, int count, int last){
        if (count >= m){
            for (int x : res) {
                System.out.print(x + " ");
            }
            System.out.println();
            return;
        }

        for (int x : arr){
            if (x != last && !visited[x]){
                visited[x] = true;
                res[count] = x;
                dfs(m, count + 1, x);
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
        dfs(m, 0, -1);
    }
}
