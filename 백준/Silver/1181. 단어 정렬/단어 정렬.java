import java.io.*;
import java.util.*;

class Words implements Comparable<Words>{
    String word;

    Words(String word){
        this.word = word;
    }

    @Override
    public int compareTo(Words o) {
        if (o.word.length() == word.length()){
            return word.compareTo(o.word);
        }

        else return word.length() - o.word.length();
    }
}


public class Main {

    public static void solution(char[][] arr, String s)  {

    }

    public static void main(String[] args) throws IOException {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();

        TreeSet<Words> tr = new TreeSet<>();
        for (int i = 0; i < n; i++) tr.add(new Words(in.nextLine()));

        ArrayList<Words> arr = new ArrayList<>(tr);

        Collections.sort(arr);

        for (Words x : arr) System.out.println(x.word);
    }
}