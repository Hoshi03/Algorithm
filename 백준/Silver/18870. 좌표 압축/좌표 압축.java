import java.util.*;
import java.io.*;

        /*
        일단 입력받은걸 arr에 순차적으로 key형태로 저장
        받은걸 set에 저장
        map<int, int>에 정렬된걸 넣으면서 순차적으로 0 1 2 3 4 식으로 증가
        map.get(arr[i]) 형태로 가져온걸 stringbuilder에 저장
        stringbuilder 출력
         */

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        Set<Integer> set = new TreeSet<>();
        Map<Integer, Integer> mmap = new HashMap<>();
        StringTokenizer st= new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++){
            int tmp = Integer.parseInt(st.nextToken());
            arr[i] = tmp;
            set.add(tmp);
        }

        int tmp = 0;
        for (int x : set){
            mmap.put(x, tmp++);
        }

        for (int i = 0; i < n; i++){
            sb.append(mmap.get(arr[i])).append(" ");
        }

        System.out.println(sb);
    }
}