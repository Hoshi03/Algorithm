import java.lang.reflect.Array;
import java.util.*;

class Main {

    public float solution(int[] arr) {
        float res = 0;
        long max = (long)Arrays.stream(arr).max().getAsInt();
        for(int x : arr) {
            res += x * 100.0 / max / arr.length;
        }
        return res;
    }

    public static void main(String[] args) {
        Main T = new Main();
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++){
            arr[i] = in.nextInt();
        }
        System.out.println(T.solution(arr));

    }
}