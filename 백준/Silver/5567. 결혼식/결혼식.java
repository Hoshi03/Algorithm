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
        int ans = 0;

        arr = new ArrayList[N+1];
        visit = new boolean[N+1];
        dist = new int[N+1];
        for (int i = 1; i <= N; i++) arr[i] = new ArrayList<>();
        for (int i = 1; i <=M; i++ ){
            int a = in.nextInt();
            int b = in.nextInt();
            arr[a].add(b);
            arr[b].add(a);
        }

        bfs(1);


        for (int i = 2; i <= N; i++) {
            if (dist[i] == 1 || dist[i] == 2) ans++;
        }

        System.out.println(ans);
    }
}