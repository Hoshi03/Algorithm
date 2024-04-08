import java.io.*;
import java.sql.Array;
import java.util.*;

public class Main {

    static int N, cnt;

    static String[] a;
    static int[][] arr;
    static boolean[][] visited;
    static ArrayList<Integer> group; // dfs 결과를 기록할 배열

    // 시계방향으로 상하좌우를 탐색하는 배열
    static int[][] dir = {{-1,0},{0,1},{1,0},{0,-1}};

    static void dfs(int x, int y){
        visited[x][y] = true;
        cnt++;
        
        //상하좌우 돌면서 확인하기
        for (int i =0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue; //범위 벗어난건지 체크
            if (!visited[nx][ny] && arr[nx][ny] == 1){
                dfs(nx,ny);
            }
        }
    }

    static void solution(){
        group = new ArrayList<>();
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (!visited[i][j] && arr[i][j] == 1){
                    cnt = 0;
                    dfs(i, j);
                    group.add(cnt);
                }
            }
        }

        Collections.sort(group);
        System.out.println(group.size());
        for (int x : group) System.out.println(x);
    }


    public static void main(String[] args) throws IOException {
        Scanner in =new Scanner(System.in);

        N = in.nextInt();
        visited = new boolean[N][N];
        arr = new int[N][N];
        in.nextLine();

        for (int i = 0; i < N; i++) {
            String s = in.nextLine();
            for (int j = 0; j < N; j++)
                arr[i][j] = s.charAt(j) - '0';
        }
        solution();
    }
}