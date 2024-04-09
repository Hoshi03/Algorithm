import java.util.*;

public class Main {

    static int N, M, res = 0;

    static ArrayList<Integer>[] arr;
    static boolean[] visited;

    static void bfs(int x){
        Queue<Integer> queue = new LinkedList<>();
        queue.add(x);
        visited[x] = true;
        while (!queue.isEmpty()){
            int tmp = queue.poll();
            res++;
            for (int y : arr[tmp]){
                if (visited[y]) continue;
                queue.add(y);
                visited[y] = true;
            }
        }
    }


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        N = in.nextInt(); // 노드 갯수
        M = in.nextInt(); // 간선 갯수

        arr = new ArrayList[N+1];
        visited = new boolean[N+1];

        for (int i = 1; i <= N; i++) arr[i] = new ArrayList<>();
        for (int i = 1; i <= M; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            arr[a].add(b);
            arr[b].add(a);
        }

        bfs(1);
        System.out.println(res-1);
    }
}