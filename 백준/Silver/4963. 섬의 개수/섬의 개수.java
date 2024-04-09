import java.io.*;
import java.util.*;

public class Main {
    static int M, N;

    static StringTokenizer st;
    static String s;

    static ArrayList<Integer> res = new ArrayList<>();

    //8방향;
    static int[][] dir = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
    static int[][] arr;
    static boolean[][] visited;

    static void solution(){
        int tmp = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (!visited[i][j] && arr[i][j] == 1){
                    tmp++;
                    dfs(i,j);
                }
            }
        }
        res.add(tmp);
    }

    static void dfs(int x, int y){
        visited[x][y] = true;
        for (int i = 0; i < dir.length; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (visited[nx][ny] || arr[nx][ny] == 0) continue;
            dfs(nx,ny);
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true){
            s = br.readLine();
            st = new StringTokenizer(s);
            M = Integer.parseInt(st.nextToken()); // 너비 - M
            N = Integer.parseInt(st.nextToken()); // 높이 - N
            if (M == 0 && N == 0) break; // 종료조건
            arr = new int[N][M];
            visited = new boolean[N][M];

            for (int i = 0; i < N; i++){
                s = br.readLine();
                st = new StringTokenizer(s);
                for (int j = 0; j < M; j++){
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            solution();
        }

        for (int x : res) System.out.println(x);
    }
}