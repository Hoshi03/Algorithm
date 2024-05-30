import java.util.*;
import java.io.*;

public class Main{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        boolean isEmpty = false;
        boolean isFliped = false;

        while (n --> 0){
            isFliped  = false;
            isEmpty = false;
            Deque<String> deque = new LinkedList<>();

            String func = br.readLine();
            int len = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine(), "[,]");
            for (int i = 0; i < len; i++) {
                deque.offer(st.nextToken());
            }

            for (int i = 0; i < func.length(); i++){
                if (func.charAt(i) == 'R'){
                    if (isFliped) isFliped= false;
                    else isFliped = true;
                }
                else if (func.charAt(i) == 'D'){
                    if (deque.isEmpty()){
                        isEmpty = true;
                        break;
                    }
                    else {
                        // R이 홀수번 호출되서 뒤집힌 상태면 뒤에서 부터 하나를 제거하고
                        if (isFliped){
                            deque.removeLast();
                        }
                        // 아니면 원래 D의 동작대로 앞에서부터 하나를 제거
                        else deque.removeFirst();
                    }
                }
            }

            StringBuilder sb = new StringBuilder();
            if (!isEmpty){
                if (isFliped){
                    while (!deque.isEmpty()) {
                        sb.append(deque.removeLast());
                        if (!deque.isEmpty()) sb.append(",");
                    }
                }
                else {
                    while (!deque.isEmpty()){
                        sb.append(deque.removeFirst());
                        if (!deque.isEmpty()) sb.append(",");
                    }
                }

                bw.write("[" + sb + "]\n");
            }

            else bw.write("error\n");
        }
        bw.flush();
    }
}