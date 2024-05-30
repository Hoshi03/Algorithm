import java.util.*;
import java.io.*;

public class Main{

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        in.nextLine();

        int left = 0, right = 0;
        boolean gal = true;

        while (n-- > 0){
            gal = true;
            left = 0; right = 0;
            String s = in.nextLine();
            for (int i =0; i < s.length(); i++){
                char cur = s.charAt(i);
                if (cur == '(') left++;
                else if(cur == ')')right++;
                if (right > left){
                    gal = false;
                    break;
                }
            }

            if (left != right) gal = false;
            if (gal )System.out.println("YES");
            else System.out.println("NO");
        }

    }
}