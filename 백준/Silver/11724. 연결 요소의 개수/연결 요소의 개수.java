import java.io.*;
import java.sql.Array;
import java.util.*;

public class Main {
    static int N, M;
    static int res = 0;
    static int[][] arr;
    static boolean[] visited;

    static void dfs(int x){
        visited[x] = true;

        for (int i = 1; i <= N; i++){
            if (arr[x][i] == 0) continue;
            if (visited[i]) continue;
            dfs(i);
        }
    }

    static void solution(){
        for (int i = 1; i <= N; i++){
            if (!visited[i]){
                res++;
                dfs(i);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner in =new Scanner(System.in);
        N = in.nextInt();
        M = in.nextInt();
        arr = new int[N+1][N+1];
        visited = new boolean[N+1];
        for (int i = 1; i <= M; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            arr[a][b] = 1;
            arr[b][a] = 1;
        }
        solution();
        System.out.println(res);
    }
}