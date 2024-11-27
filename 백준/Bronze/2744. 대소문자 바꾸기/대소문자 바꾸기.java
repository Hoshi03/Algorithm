import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String s = br.readLine();
        char[] arr = s.toCharArray();
        for (int i = 0; i < arr.length; i++){
            if (arr[i] >= 97) arr[i] -= 32;
            else arr[i] += 32;
        }

        for (char x : arr) System.out.print(x);

    }
}