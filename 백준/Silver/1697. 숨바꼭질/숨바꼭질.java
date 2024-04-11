import java.util.*;
import java.io.*;

public class Main{

    static int N, M, res = 0, ans = Integer.MAX_VALUE;

    static int maxPos = 100000;

    static boolean[] visit;
    static int[] dist;

    static void bfs(int x){
        Queue<Integer> queue = new LinkedList<>();
        queue.add(x);
        visit[x] = true;
        dist[x] = 0;

        while (!queue.isEmpty()){
            x = queue.poll();
            int y = x-1;
            if (y >= 0 && y <= maxPos && !visit[y]){
                queue.add(y);
                visit[y] = true;
                dist[y] = dist[x]+1;
            }

            y = x+1;
            if (y >= 0 && y <= maxPos && !visit[y]){
                queue.add(y);
                visit[y] = true;
                dist[y] = dist[x]+1;
            }

            y = x*2;
            if (y >= 0 && y <= maxPos && !visit[y]){
                queue.add(y);
                visit[y] = true;
                dist[y] = dist[x]+1;
            }
        }
    }


    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        M = in.nextInt();
        visit = new boolean[maxPos+2];
        dist = new int[maxPos+2];
        bfs(N);
        System.out.println(dist[M]);

    }
}