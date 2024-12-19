import java.util.*;
import java.io.*;

class Book{
    String name;
    int count;
    public Book(String name, int count){
        this.name = name;
        this.count = count;
    }
}

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<String, Integer> mmap = new HashMap<>();

        while (n --> 0){
            String s = br.readLine();
            mmap.put(s, mmap.getOrDefault(s,0)+1);
        }
        ArrayList<Book> arr = new ArrayList<>();
        for (String x : mmap.keySet()){
            arr.add(new Book(x, mmap.get(x)));
        }

        arr.sort((a,b) -> {
           if (a.count == b.count){
               return a.name.compareTo(b.name);
           }
           else return b.count - a.count;
        });

        System.out.println(arr.get(0).name);
    }
}