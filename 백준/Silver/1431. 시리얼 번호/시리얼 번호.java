import java.util.*;
import java.io.*;

class Guitar {
    String serial;
    int sum;

    public Guitar(String serial){
        this.serial = serial;
        this.sum = calculateSum();
    }

    private int calculateSum() {
        int totalSum = 0;
        for (int i = 0; i < serial.length(); i++) {
            int tmp = serial.charAt(i) -'0';
            if (tmp < 10) {
                totalSum += tmp;
            }
        }
        return totalSum;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        ArrayList<Guitar> arr = new ArrayList<>();
        for (int i = 0; i < n ; i++){
            String s = br.readLine();
            arr.add(new Guitar(s));
        }

        arr.sort((a, b) -> {
            if (a.serial.length() != b.serial.length()) {
                return a.serial.length() - b.serial.length();
            }

            if (a.sum != b.sum) {
                return a.sum - b.sum;
            }

            return a.serial.compareTo(b.serial);
        });

        for (Guitar x : arr){
            System.out.println(x.serial);
        }
    }
}
