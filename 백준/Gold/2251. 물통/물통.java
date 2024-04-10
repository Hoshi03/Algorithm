import java.util.*;
import java.io.*;

class State{
    int[] x = new int[3];
    State(int[] _x){
        for (int i = 0; i < 3; i++) x[i] = _x[i];
    }

    State move(int from,int to,int[] Limit){
        // from 물통에서 to 물통으로 물을 옮긴다.
        int[] nX = new int[]{x[0], x[1], x[2]};
        if (x[from] + x[to] <= Limit[to]){  // 만약 from 을 전부 부을 수 있다면
            nX[to] = nX[from] + nX[to];
            nX[from] = 0;
        }

        else{  // from 의 일부만 옮길 수 있는 경우
            if (nX[from] - (Limit[to] - nX[to]) >= 0){
                nX[from] -= Limit[to] - nX[to];
                nX[to] = Limit[to];
            }
        }
        return new State(nX);
    }
}

public class Main {

    static int[] Limit;
    static boolean[] possible;
    static boolean[][][] visit;
    static ArrayList<Integer> res;

    static void bfs(int x1, int x2, int x3) {
        Queue<State> Q = new LinkedList<>();
        visit[x1][x2][x3] = true;
        Q.add(new State(new int[]{x1, x2, x3}));

        while (!Q.isEmpty()) {
            State st = Q.poll();
            if (st.x[0] == 0) possible[st.x[2]] = true;
            for (int from = 0; from < 3; from++) {
                for (int to = 0; to < 3; to++) {
                    if (from == to) continue; // 같은 물통끼리 옮기는 경우는 의미 X
                    // i 번 물통에서 j 번 물통으로 물을 옮긴다.
                    State nxt = st.move(from, to, Limit);

                    // 만약 바뀐 상태를 탐색한 적이 없다면
                    if (!visit[nxt.x[0]][nxt.x[1]][nxt.x[2]]) {
                        visit[nxt.x[0]][nxt.x[1]][nxt.x[2]] = true;
                        Q.add(nxt);
                    }
                }
            }
        }
    }

    static void solution() {
        bfs(0, 0, Limit[2]);
        for (int i=0;i<=200;i++){
            if (possible[i]) res.add(i);
        }
        for (int x : res) System.out.print(x + " ");
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Limit = new int[3];
        for (int i = 0; i < 3; i++) Limit[i] = in.nextInt();
        //visit 배열을 a,b,c 3개를 모두 탐색하기 위해서 3차원 배열로 작성해야한다
        visit = new boolean[201][201][201];
        possible = new boolean[201];
        res = new ArrayList<>();
        solution();
    }
}