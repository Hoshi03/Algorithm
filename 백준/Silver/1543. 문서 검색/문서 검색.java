import java.util.*;

public class Main {

    public static int solution(String s1, String s2){

        int cnt = 0;
        int res = 0;

        while (true){
            int start = s1.indexOf(s2, cnt);

            if (start < 0)  break;

            else {
                cnt = start + s2.length();
                res++;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String s1 = in.nextLine();
        String s2 = in.nextLine();
        System.out.println(solution(s1,s2));
    }
}
