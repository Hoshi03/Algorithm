import java.util.*;
import java.io.*;

public class Main{

    static int N, M;

    static boolean[] visit;
    static int[] dist;

    static ArrayList<Integer>[] arr;

    static void bfs(int x){
        Queue<Integer> q = new LinkedList<>();
        visit[x] = true;
        dist[x] = 0;
        q.add(x);
        while (!q.isEmpty()){
            x = q.poll();
            for (int y : arr[x]){
                if (visit[y]) continue;
                q.add(y);
                visit[y] = true;
                dist[y] = dist[x]+1;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        M = in.nextInt();

        int min = Integer.MAX_VALUE; // 케빈베이컨 값이 제일 작은 값
        int tmp = 0;
        int ans = 0; // 작은 값인 사람

        arr = new ArrayList[N+1];
        for (int i = 1; i <= N; i++) arr[i] = new ArrayList<>();

        for (int i = 1; i <=M; i++ ){
            int a = in.nextInt();
            int b = in.nextInt();
            arr[a].add(b);
            arr[b].add(a);
        }

        for (int i = 1; i <= N; i++){
            visit = new boolean[N+1];
            dist = new int[N+1];
            tmp = 0;
            bfs(i);
            for (int j = 1; j <= N; j++){
                if (j != i) tmp += dist[j];
            }
            if (min > tmp){
                min = tmp;
                ans = i;
            }
        }
        System.out.println(ans);
    }
}