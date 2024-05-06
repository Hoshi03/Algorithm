import java.util.*;
import java.io.*;


class Main
{
    public static void main (String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        int[] alphabet = new int[26];
        int n = in.nextInt(), max = Integer.MIN_VALUE, cnt = 0, rt = 0, len = 0;
        char[] arr = in.next().toCharArray();
        for (int i = 0; i < arr.length; i++){
            while (rt < arr.length && cnt <= n){
                if (alphabet[arr[rt] - 97] == 0){
                    if (cnt == n) break;
                    else if (cnt < n) {
                        cnt++;
                    }
                }
                alphabet[arr[rt]-97] = alphabet[arr[rt]-97]+1;
                rt++;
                len++;
            }

            max = Math.max(len, max);
            alphabet[arr[i] - 97] = alphabet[arr[i]-97] - 1;
            if (alphabet[arr[i]-97] == 0){
                cnt--;
            }
            len--;
        }
        System.out.println(max);
    }
}