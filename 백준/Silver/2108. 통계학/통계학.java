import java.io.*;
import java.util.*;


class Pair{
    public int idx;
    public int value;

    public Pair(int idx, int value) {
        this.idx = idx;
        this.value = value;
    }
}

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        HashMap<Integer, Integer> map = new HashMap<>();
        ArrayList<Integer> arr = new ArrayList<>();
        double sum = 0;
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++){
            int tmp = Integer.parseInt(br.readLine());
            arr.add(tmp);
            map.put(tmp, map.getOrDefault(tmp,0)+1);
            sum += tmp;
        }

        int cnt = 0;
        for (Integer key : map.keySet()) {
            cnt = Math.max(cnt, map.get(key));
        }

        ArrayList<Integer> arr2 = new ArrayList<>();

        for (Integer key : map.keySet()) {
//            System.out.println(key + " " + map.get(key));
            if (map.get(key) == cnt) arr2.add(key);
        }

        Collections.sort(arr);
        Collections.sort(arr2);

//        for (int x : arr2) System.out.println(x);

        System.out.println(Math.round(sum/n));
        System.out.println(arr.get(n/2));
        if (arr2.size() == 1) System.out.println(arr2.get(0));
        else System.out.println(arr2.get(1));
        System.out.println(arr.get(n-1) - arr.get(0));

    }
}