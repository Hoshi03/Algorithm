import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[] arr = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt)
                .toArray();

        Deque<Integer> stack = new ArrayDeque<>();
        // 맨 오른쪽에서 시작해서 왼쪽으로 진행하면서 오큰수를 찾는다
        for (int i = n - 1; i >= 0; i--) {
            int tmp  = arr[i];
            // 스택의 맨 위 원소가 arr[i]보다 작으면 오큰수가 될수 없다
            while (!stack.isEmpty() && stack.peek() <= arr[i]) stack.pop();
            // 스택에 남아있는건 오른쪽부터 왼쪽 방향으로  차례대로 arr[i]보다 큰 원소니 peek가 오큰수이다
            arr[i] = (stack.isEmpty() ? -1 : stack.peek());
            // 스택에 arr[i]를 넣고 반복문을 돌면서 arr[i-1]의 오큰수가 될수 있는지 판별한다
            stack.push(tmp);
        }

        StringBuilder sb = new StringBuilder();
        for (int x : arr) sb.append(x).append(" ");
        System.out.println(sb);
    }
}