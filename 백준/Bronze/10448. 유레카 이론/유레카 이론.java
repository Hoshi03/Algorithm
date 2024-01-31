import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class Main {

    public static ArrayList<Integer> solution(ArrayList<Integer> list, int[] arr )  {
        ArrayList<Integer> res = new ArrayList<>();

        for (int x : arr){

            boolean is3 = false;
            int tmp = 0;

            for (int i =0; i < list.size(); i++){
                tmp = list.get(i);
                for (int j = 0; j < list.size(); j++){
                    tmp = list.get(i) + list.get(j);
                    for (int k =0; k < list.size(); k++){
                        if (tmp + list.get(k) == x ) {
                            is3 = true;
                            break;
                        }
                    }
                }
            }

            if (is3) res.add(1);
            else res.add(0);

        }

        return res;
    }

    public static void main(String[] args) throws IOException {

        Scanner in = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<>();
        for (int i =1; i <= 1000; i++){
           if (i*(i+1)/2 <= 1000) list.add(i*(i+1)/2);
           else break;
        }

        int n = in.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = in.nextInt();

        for (int x : solution(list,arr)) System.out.println(x);

    }
}