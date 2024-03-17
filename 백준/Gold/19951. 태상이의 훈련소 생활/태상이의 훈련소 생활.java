import java.io.*;
import java.util.*;

class Main
{
    public static void main (String[] args) throws IOException {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();


        int[] arr= new int[n+1];

        for (int i = 1; i <= n; i++) arr[i] = in.nextInt();

        //땅 팔곳 시작, 끝나는 위치를 기록할 delta 배열
        int[] delta = new int[n+2];
        
        //delta 배열의 누적합을 구할 sumdelta 배열
        int[] sumdelta = new int[n+2];

        //delta 배열의 땅 파는 곳을 저장해둔다
        while (m-- > 0){
            int start = in.nextInt();
            int end = in.nextInt();
            int meter = in.nextInt();
            delta[start] += meter;
            delta[end + 1] -= meter;
        }

        for (int i = 1; i <= n; i++){
            sumdelta[i] = sumdelta[i-1] + delta[i];
            arr[i] += sumdelta[i];
        }

        for (int x = 1; x <= n; x++) System.out.print(arr[x] + " ");


    }
}