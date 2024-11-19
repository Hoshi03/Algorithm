import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        while (true) {
            ArrayList<Integer> arr = new ArrayList<>();
            st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                arr.add(Integer.parseInt(st.nextToken()));
            }
            if (arr.get(0).equals(arr.get(1)) &&
                    arr.get(1).equals(arr.get(2)) && arr.get(0) == 0) break;
            Collections.sort(arr);
            if (Math.pow(arr.get(0), 2) + Math.pow(arr.get(1), 2) == Math.pow(arr.get(2), 2)){
                System.out.println("right");
            }
            else System.out.println("wrong");
        }
    }
}