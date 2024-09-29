import java.io.*;
import java.util.*;

class Main
{
    public static void main (String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] start = br.readLine().split(" ");

        int n = Integer.parseInt(start[0]);
        int max = Integer.parseInt(start[1]);

        Map<Integer,Integer> map = new LinkedHashMap<>();
        int i = 0;

        String[] nums = br.readLine().split(" ");

        for (String num : nums) {
            int number = Integer.parseInt(num);
            map.put(number, map.getOrDefault(number, 0) + 1);
        }

        ArrayList<Integer> keySet = new ArrayList<>(map.keySet());

        keySet.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if (o1 != o2){
                    return  map.get(o2) - map.get(o1);
                }
                return 0;
            }
        });

        for (Integer key : keySet) {
            for (int tmp =0; tmp < map.get(key); tmp++){
                System.out.print(key + " ");
            }
        }
    }
}