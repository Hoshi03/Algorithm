import java.io.*;
import java.util.*;

class Person implements Comparable<Person>{
    int age;
    String name;

    Person(int age, String name){
        this.name = name;
        this.age = age;
    }

    @Override
    public int compareTo(Person o) {
        return  age - o.age;
    }
}


public class Main {

    public static void solution(char[][] arr, String s)  {

    }

    public static void main(String[] args) throws IOException {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        ArrayList<Person> arr = new ArrayList<>();

        for (int i = 0; i < n; i++) arr.add(new Person(in.nextInt(), in.nextLine()));


        Collections.sort(arr);

        for (Person x : arr) System.out.println(x.age + "" + x.name);
    }
}