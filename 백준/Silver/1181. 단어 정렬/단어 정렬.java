import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        Set<String> set = new HashSet<>();
        for (int i = 0; i < n; i++){
            set.add(br.readLine());
        }

        ArrayList<String> arr = new ArrayList<>();

        for (String x : set) arr.add(x);

        Collections.sort(arr, ((a, b) -> {
            if (a.length() == b.length()) {
                return a.compareTo(b);
            } else {
                return a.length() - b.length();
            }
        }));

        for (String x : arr){
            sb.append(x).append('\n');
        }

        System.out.println(sb);
    }
}