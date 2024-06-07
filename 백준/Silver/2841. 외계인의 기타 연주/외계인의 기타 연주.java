import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        //1~6번 줄에 해당하는 스택 6개
        ArrayList<Deque<Integer>> strings = new ArrayList<>();
        for (int i = 0; i <= 6; i++) strings.add(new ArrayDeque<>());

        int n = in.nextInt();
        int flats = in.nextInt();
        int count = 0;

        while (n --> 0){
            int string = in.nextInt();
            int flat = in.nextInt();
            Deque<Integer> currentString = strings.get(string);

            if (currentString.isEmpty()){
                currentString.push(flat);
                count++;
            }

            else {
                if (currentString.peek() < flat){
                    currentString.push(flat);
                    count++;
                }
                else if (currentString.peek() > flat) {
                    while (!currentString.isEmpty() && currentString.peek() > flat){
                        Integer pop = currentString.pop();
                        count++;
                    }

                    if (!currentString.isEmpty() && currentString.peek() != flat){
                        currentString.push(flat);
                        count++;
                    }

                    else if (currentString.isEmpty()) {
                        currentString.push(flat);
                        count++;
                    }
                }
            }
        }
        System.out.println(count);
    }
}