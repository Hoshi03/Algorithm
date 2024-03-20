import java.io.*;
import java.util.*;

class Main
{
    public static void main (String[] args) throws IOException {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr= new int[n];

        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }

        //set에 a + b 를 저장
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                set.add(arr[i]+arr[j]);
            }
        }

        int max = Integer.MIN_VALUE;


        //a + b = x(arr[i]) - c 면 답이 될 수 있음
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (set.contains(arr[i] - arr[j])){
                    max = Math.max(max, arr[i]);
                }
            }
        }

        System.out.println(max);
    }
}