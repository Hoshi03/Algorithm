import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class Main {

    public static String solution(int a, int b)  {
        String res = "";
        StringBuilder sb = new StringBuilder(res);

        while (a > 0){
            int tmp = a % b;
            a /= b;

            if (tmp < 10) sb.append(tmp);
            else sb.append((char)('A' + tmp - 10));
        }


        return sb.reverse().toString();

    }

    public static void main(String[] args) throws IOException {

        Scanner in = new Scanner(System.in);

        int a = in.nextInt();
        int b = in.nextInt();
        System.out.println(solution(a,b));
    }
}