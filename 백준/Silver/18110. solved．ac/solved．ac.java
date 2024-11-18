import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) arr.add(Integer.parseInt(br.readLine()));
        int start = (int) Math.round((double) (n * 15) /100);
//        System.out.println(start + " " + (n-start));
        Collections.sort(arr);
        double tmp = 0;
        for(int i = start; i < n-start; i++){
            tmp += arr.get(i);
        }

//        System.out.println(tmp);
        System.out.println((int)  Math.round(tmp /(n-start*2)));
    }
}