import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class Main {

    public static void solution(char[][] arr, String s)  {

    }

    public static void main(String[] args) throws IOException {

        Scanner in = new Scanner(System.in);
        int x = in.nextInt();
        int n = in.nextInt();

        ArrayList<Integer> arr = new ArrayList<>();
        ArrayList<Character> name = new ArrayList<>();

        for (int i = 0; i < n; i++){
            char a = in.next().charAt(0);
            int tmp = in.nextInt();

            if ((float)tmp / x > 0.05){
                arr.add(tmp);
                name.add(a);
            }
        }

        // 이름, 초기 투표수를 가진 배열리스트 2개

        int[] votes = new int[14 *  arr.size()];
        for (int i = 0; i < arr.size(); i++){
            int tmp = i * 14;
            for (int j = 1; j <= 14; j++ ){
                votes[tmp] = arr.get(i) / j;
                tmp++;
            }
        }

        Arrays.sort(votes);

        //정렬된 배열의 뒤에 14개, 큰것부터 가져오기
        int[] res = new int[arr.size()];
        for (int i = votes.length-1; i > votes.length-14-1; i--){
            for (int j = 0; j < arr.size(); j++){
                for (int k = 1; k <= 14; k++){
                    if (arr.get(j) / k == votes[i]){
                        res[j] += 1;
                        break;
                    }
                }
            }
        }


        Map<Character, Integer> map = new TreeMap<>();

        for (int i = 0; i < arr.size(); i++){
            map.put(name.get(i),res[i]);
        }

        for (Character nKey : map.keySet()) {
            System.out.println(nKey + " " + map.get(nKey));
        }

    }
}