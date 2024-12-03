import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        while (n --> 0){
            int target = Integer.parseInt(br.readLine());
            int cnt = 0;
            boolean isTriangle = false;
            int[] arr = new int[1001];
            for(int i = 1; i <= 1000; i++){
                int tmp = i * (i + 1) / 2;
                if (tmp >= target) break;
                arr[cnt++] = tmp;
            }

            for (int i = 0; i < cnt; i++){
                if (isTriangle) break;
                for (int j = 0; j < cnt; j++){
                    if (isTriangle) break;
                    for (int k = 0; k < cnt; k++){
                        if (arr[i] + arr[j] + arr[k] == target) {
                            isTriangle = true;
                            break;
                        }
                    }
                }
            }
            if (!isTriangle) System.out.println(0);
            else System.out.println(1);
        }
    }
}
