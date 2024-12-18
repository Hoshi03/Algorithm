import java.util.*;
import java.io.*;

class People {
    int age;
    String name;
    int idx;

    public People(int age, String name, int idx){
        this.age = age;
        this.name = name;
        this.idx = idx;
    }
}

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        ArrayList<People> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int age = Integer.parseInt(st.nextToken());
            String name = st.nextToken();
            arr.add(new People(age, name, i));
        }
        arr.sort((a, b) ->{
            if (a.age == b.age){
                return a.idx - b.idx;
            }

            else {
                return a.age - b.age;
            }
        });

        for (People x : arr){
            System.out.println(x.age + " " + x.name);
        }
    }
}