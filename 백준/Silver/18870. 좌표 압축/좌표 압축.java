import java.io.*;
import java.util.*;

class Main
{
    public static void main (String[] args) throws IOException {

       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

       int n = Integer.parseInt(br.readLine());

       String[] input =  br.readLine().split(" ");

        //중복 제거해서 정렬할 트리맵
       TreeMap<Long, Integer> treeMap = new TreeMap<>();

       for (int i =0; i < n; i++){
           treeMap.put(Long.parseLong(input[i]),0);
       }

        int idx = 0;

       //트리맵 순회하면서 밸류에 자기보다 작은 숫자 갯수를 넣어둠
        for (Map.Entry<Long, Integer> x : treeMap.entrySet()){
            Long x1 = x.getKey();
            treeMap.put(x1,idx++);
        }

        for (int i = 0; i < n; i++){
            bw.write(treeMap.get(Long.parseLong(input[i])) + " ");
        }
        bw.flush();
    }
}