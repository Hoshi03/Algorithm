import java.util.*;

public class Main {

    public static char solution(String s1){
        String s = s1.toUpperCase();
        int[] arr = new int[26];
        char res = 0;
        int max = Integer.MIN_VALUE;

        for (char x : s.toCharArray()){
            arr[x - 'A'] += 1;
        }

        for (int i = 0; i < arr.length; i++){
            if (arr[i] == max && max > 0) res = '?';
            else if (arr[i] > max){
                max = arr[i];
                res = (char)(i + 'A');
            }
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String s1 = in.nextLine();
        System.out.println(solution(s1));
    }
}
