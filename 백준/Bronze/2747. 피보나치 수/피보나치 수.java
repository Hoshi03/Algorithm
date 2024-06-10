import java.util.*;
import java.io.*;


class Main
{
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        Deque<Character> deque = new ArrayDeque<>();
        int n = in.nextInt();
        int[] arr = new int[n+1];
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2; i <= n; i++) arr[i] = arr[i-1] + arr[i-2];
        System.out.println(arr[n]);

    }
}