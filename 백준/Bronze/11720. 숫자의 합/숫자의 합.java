import java.util.*;

class Main {

    public int solution(int[] arr) {
        int res = 0;
        for(int x : arr) res += x;
        return res;
    }

    public static void main(String[] args) {
        Main T = new Main();
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String m = in.next();
        String[] split = m.split("");
        int[] arr = new int[n];
        for (int i = 0; i < split.length; i++){
            arr[i] = Integer.parseInt(split[i]);
        }
        System.out.println(T.solution(arr));

    }
}