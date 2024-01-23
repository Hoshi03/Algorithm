import java.util.*;

public class Main {

    public static String Solution(String s){
        char[] arr = s.toCharArray();
        for (int i = 0; i < arr.length; i++){
            if (arr[i] >= 65 && arr[i] <= 90 ) arr[i] += 32;
            else if (arr[i] >= 97 && arr[i] <= 122) arr[i] -= 32;
        }

        return String.valueOf(arr);

    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String s = in.nextLine();
        System.out.println(Solution(s));
    }
}
