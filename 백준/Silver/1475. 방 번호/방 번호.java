import java.util.*;
import java.io.*;


class Main
{
    public static void main (String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        int[] arr = new int[s.length()];
        for (int i = 0; i < s.length(); i++) arr[i] = s.charAt(i) - '0';

        int res = 0, tmp = 0;
        int[] count = new int[10];

        for (int i = 0; i < s.length(); i++){
            tmp = arr[i];
            //원소가 없을때
            if (count[tmp] == 0){
                if (tmp == 6 || tmp == 9){
                    if (count[6] == 0 && count[9] == 0){
                        for (int j = 0; j < 10; j++) count[j]++;
                        count[tmp]--;
                        res++;
                    }
                    else if (count[6] > 0) count[6]--;
                    else if (count[9] > 0) count[9]--;
                }

                else {
                    for (int j = 0; j < 10; j++) count[j]++;
                    count[tmp]--;
                    res++;
                }
            }
            // 원소가 잇으면 갯수를 하나 빼주기
            else count[tmp]--;
        }
        System.out.println(res);
    }
}