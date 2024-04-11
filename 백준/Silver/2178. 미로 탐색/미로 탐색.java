import java.util.*;
import java.io.*;

class Node{
    int x, y, gap;
    Node(int x, int y, int gap){
        this.x = x;
        this.y = y;
        this.gap = gap;
    }
}

public class Main {

    static int[][] dir = {{1,0},{0,1},{-1,0},{0,-1}};
    static String s; static StringTokenizer st;
    static int N, M;
    static int[][] dist;
    static boolean[][] isVisited;
    static Node[][] arr;
    static void bfs(int x, int y){

        Queue<Node> queue = new LinkedList<>();
        queue.add(arr[x][y]);
        isVisited[x][y] = true;
        dist[x][y] = 1;

        while (!queue.isEmpty()){
            Node tmp = queue.poll();

            for (int i = 0; i < 4; i++){
                int nx = tmp.x + dir[i][0];
                int ny = tmp.y + dir[i][1];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if (isVisited[nx][ny]) continue;
                if (arr[nx][ny].gap == 1){
                    queue.add(arr[nx][ny]);
                    isVisited[nx][ny] = true;
                    dist[nx][ny] = dist[tmp.x][tmp.y]+1;
                }
            }
        }
    }



    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        s = br.readLine();
        st = new StringTokenizer(s);
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new Node[N][M];
        isVisited = new boolean[N][M];
        dist = new int[N][M];


        for (int i = 0; i < N; i++){
            s = br.readLine();
            for (int j = 0; j < M; j++) {
                arr[i][j] = new Node(i,j,s.charAt(j) - '0');
            }
        }

        bfs(0,0);
        System.out.println(dist[N-1][M-1]);
    }
}