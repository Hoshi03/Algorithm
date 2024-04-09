import java.io.*;
import java.sql.Array;
import java.util.*;

public class Main {
    static int N, M;
    static int res = 0;
    static int[][] arr;
    static boolean[] visited;

    static void solution(){
        for (int i = 1; i <= N; i++){
            if (!visited[i]) {
                bfs(i);
                res++;
            }
        }
    }

    static void bfs(int x){
        Queue<Integer> que = new LinkedList<>();
        que.add(x);
        visited[x] = true;
        while (!que.isEmpty()){
            int tmp = que.poll();
            for (int i = 1; i <= N; i++){
                if (visited[i]) continue;
                if (arr[tmp][i] != 1) continue;
                que.add(i);
                visited[i] = true;
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