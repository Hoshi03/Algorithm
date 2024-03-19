import javax.print.DocFlavor;
import java.io.*;
import java.util.*;


public class Main {

    public static void main(String[] args) throws IOException {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int res = 0;

        Set<String> set = new HashSet<>();
        for (int i = 0; i <= n; i++) set.add(in.nextLine());

        for (int i = 0; i < m; i++) {
            if (set.contains(in.nextLine())) res++;
        }

        System.out.println(res);




    }
}