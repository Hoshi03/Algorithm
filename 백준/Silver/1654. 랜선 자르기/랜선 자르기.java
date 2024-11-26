import java.io.*;
import java.util.*;

public class Main {
    static ArrayList<Integer> arr = new ArrayList<>();
    static long n, k, max, mid, res = 0;

    static boolean binary_search(long mid){
        int cnt = 0;
        for (int x : arr){
            cnt += (int) (x / mid);
        }
        return cnt >= n;
    }

    static void solution(){
        long lt = 1;
        long rt = max;
        while (lt <= rt){
            mid = (lt + rt) / 2;
            if(binary_search(mid)) {
                res = Math.max(res,mid);
                lt = mid+1;
            }
            else rt = mid - 1;
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        k = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        for (int i = 0; i < k; i++){
            arr.add(Integer.parseInt(br.readLine()));
            max = Math.max(arr.get(i),max);
        }

        solution();
        System.out.println(res);

    }
}