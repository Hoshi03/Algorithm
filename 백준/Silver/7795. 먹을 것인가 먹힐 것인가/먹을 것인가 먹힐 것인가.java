import java.awt.*;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

class Main
{
    static int binary_search(int[] arr, int target){
        int lt = 0, rt = arr.length-1, res = 0;
        while (lt <= rt){
            int m = (lt + rt) / 2;
            if (arr[m] < target){
                lt = m+1;
                res = m+1;
            }
            else rt = m-1;
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(); // 전체 A,B 쌍의 갯수
        while (n-- > 0){
            int a = in.nextInt();
            int b = in.nextInt();
            int ans = 0;
            int[] arrA = new int[a];
            int[] arrB = new int[b];
            for (int i = 0; i < a; i++) arrA[i] = in.nextInt();
            for (int i = 0; i < b; i++) arrB[i] = in.nextInt();
            Arrays.sort(arrB);

            for (int x: arrA) ans += binary_search(arrB, x);
            in.nextLine();
            System.out.println(ans);
        }
    }
}