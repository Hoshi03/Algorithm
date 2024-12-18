import java.util.*;
import java.io.*;

class People {

}

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<String,String> mmap = new TreeMap<>();
        while (n --> 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            mmap.put(st.nextToken(), st.nextToken());
        }

        ArrayList<String> arr = new ArrayList<>();

        for (String x : mmap.keySet()){
            if (mmap.get(x).equals("enter")) arr.add(x);
        }

        Collections.sort(arr,Collections.reverseOrder());

        for (String x : arr) System.out.println(x);
    }
}