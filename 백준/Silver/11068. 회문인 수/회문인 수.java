import java.util.*;
import java.io.*;

class Main {

    public static int pal(int tmp){
        int res = 0;
        for(int i = 2; i <= tmp && i <= 64; i++){
            StringBuilder sb = new StringBuilder();
            int cur = tmp;
            while (cur != 0){
                int append = cur % i;
                // 10 넘어가면 뒤집을때 문자로 변환해줘야됨
                if (i >= 10){
                    //65~97
                    append += 65;
                    while (append-i >= 65 && append-i <= 97){
                        append -= i;
                    }
                    sb.append((char)append);
                }
                else{
                    sb.append(cur % i);
                }
                cur /= i;
            }
            String s1 = sb.toString();
            String s2 = sb.reverse().toString();
//            System.out.println(s1 + " " + s2);
            if (s1.equals(s2)){
                res = 1;
                break;
            }
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        while(n --> 0){
            int tmp = Integer.parseInt(br.readLine());
            if (String.valueOf(tmp).equals(sb.append(String.valueOf(tmp)).reverse().toString())){
                System.out.println(1);
            }
            else {
                System.out.println(pal(tmp));
            }
        }
    }
}
