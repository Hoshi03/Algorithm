import java.io.*;
import java.util.*;


class Main
{
    static int isEmpty(Queue<Integer> q){
        if (q.isEmpty()) return 1;
        else return 0;
    }

    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Queue<Integer> q = new LinkedList<>();
        int n = Integer.parseInt(br.readLine());
        int back = 0;


        while (n-- > 0){
            String[] s = br.readLine().split(" ");
            if (s[0].equals("push")){
                int tmp = Integer.parseInt(s[1]);
                back = tmp;
                q.add(tmp);
            }

            else if (s[0].equals("pop")){
                if (isEmpty(q) == 0){
                    int tmp = q.poll();
                    bw.write(tmp + "\n");
                }
                else bw.write(-1 + "\n");
            }

            else if (s[0].equals("front")) {
                if (isEmpty(q) == 0){
                    int tmp = q.peek();
                    bw.write(tmp + "\n");
                }
                else bw.write(-1 + "\n");
            }

            else if (s[0].equals("empty")){
                bw.write(isEmpty(q) + "\n");
            }

            else if (s[0].equals("back")) {
                if (q.isEmpty()) bw.write(-1 + "\n");
                else bw.write(back + "\n");
            }

            else if (s[0].equals("size")) {
                bw.write(q.size() + "\n");
            }
        }

        bw.flush();

    }
}