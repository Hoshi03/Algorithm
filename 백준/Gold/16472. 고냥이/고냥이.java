import java.util.*;
import java.io.*;


class Main
{
    public static void main (String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String s = in.next();
        char[] arr = new char[26];


        int count = 0, rt = 0, ans = 0, len = 0;
        for (int i = 0; i < s.length(); i++){
            while (rt < s.length() && count <= n){
                if (arr[s.charAt(rt) - 97] == 0){
                    if (count < n) count++;
                    else if (count == n) break;
                }
                arr[s.charAt(rt++) - 97]++;
                len++;
            }

            ans = Math.max(ans, len);
            arr[s.charAt(i) - 97]--;
            len--;
            if (arr[s.charAt(i) - 97] == 0) count--;
        }
        System.out.println(ans);

    }
}