import javax.print.DocFlavor;
import java.io.*;
import java.util.*;


public class Main {

    public static void main(String[] args) throws IOException {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();

        String[] s = in.nextLine().split(" ");

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(s[i]);

        Arrays.sort(arr);

        if (arr.length % 2 != 0) System.out.println(arr[n/2]);
        else System.out.println(arr[n/2-1]);


    }
}