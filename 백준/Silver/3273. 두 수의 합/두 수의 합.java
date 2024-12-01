import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
        int target = Integer.parseInt(br.readLine());
        int lt = 0, rt = n-1, cnt = 0;
        while (lt < rt){
            int tmp = arr[lt]+arr[rt];
            if (tmp == target){
                if (lt + 1 < rt)lt++;
                else if (rt - 1 > lt) rt--;
                else{
                    rt++;
                    lt++;
                }
                cnt++;
            }
            else if (tmp < target) lt++;
            else rt--;
        }
        System.out.println(cnt);
    }
}
