import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;

class Main
{

    static boolean isPalindrome(char[] arr, int l, int r){
        while (l <= r){
            if (arr[l] != arr[r]) return false;
            l++;
            r--;
        }
        return true;
    }



    public static void main (String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        while (n--> 0){
            String s= in.next();
            char[] arr = s.toCharArray();
            int ans = 0;
            int l = 0, r = arr.length-1;
            while (l <= r){
                if (arr[l] != arr[r]){
                    if (isPalindrome(arr,l+1,r) || isPalindrome(arr, l, r-1)) ans = 1;
                    else ans = 2;
                    break;
                }
                l++;
                r--;
            }
            System.out.println(ans);
        }
    }
}