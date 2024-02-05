import java.security.spec.RSAOtherPrimeInfo;
import java.util.*;

public class Main {

    public static void solution(int[] arr){


    }


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();

        ArrayList<String> res = new ArrayList<>();

        for (int i = 0; i < n; i++){
            //높이, 방, 사람수
            int h = in.nextInt();
            int w = in.nextInt();
            int num = in.nextInt();

            int floor = 0;
            int ho = 0;

            floor = num % h;
            if (floor == 0) floor = h;


            ho = (num % h) == 0 ? num / h  : num / h + 1;

            if (ho < 10){
                res.add(String.valueOf(floor)+0+ho);
            }
            else res.add(String.valueOf(floor)+ho);

        }

        for (String x : res) System.out.println(x);
    }
}

// 6 12 10
