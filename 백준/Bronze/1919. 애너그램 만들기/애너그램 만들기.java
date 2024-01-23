import java.util.*;

public class Main {

    public static int Solution(String s1, String s2){
        int[] arr1 = new int[26];
        int[] arr2 = new int[26];

        int res = 0;

        for (char x : s1.toCharArray()) arr1[x - 97] += 1;
        for (char x : s2.toCharArray()) arr2[x - 97] += 1;

        for(int i = 0; i < arr1.length; i++){
            res += Math.abs(arr1[i] - arr2[i]);
        }

        return res;

    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String s1 = in.nextLine();
        String s2 = in.nextLine();
        System.out.println(Solution(s1,s2));
    }
}
