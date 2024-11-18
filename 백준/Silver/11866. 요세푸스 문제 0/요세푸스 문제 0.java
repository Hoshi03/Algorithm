import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = in.nextInt();
        int m = in.nextInt();
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; i++) q.add(i);


        ArrayList<Integer> arr = new ArrayList<>();

        int cnt = 0;
        while (!q.isEmpty()){
            cnt %= m;
            int tmp = q.poll();
            if (cnt == m-1) arr.add(tmp);
            else q.add(tmp);
            cnt++;
        }

        System.out.print("<");
        for(int i = 0; i < arr.size()-1; i++) System.out.print(arr.get(i) +", ");
        System.out.print(arr.get(arr.size()-1)+">");
    }
}