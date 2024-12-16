import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();
        char[][] arr = new char[n][n];

        boolean[][] passVertical = new boolean[n][n];
        boolean[][] passHorizontal = new boolean[n][n];

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                arr[i][j] = '.';
            }
        }

        int dy = 0;
        int dx = 0;

        for (int i = 0; i < s.length(); i++){

            char tmp = s.charAt(i);
            if (tmp == 'U'){
                if (dy - 1 >= 0){
                    passVertical[dy][dx] = true;
                    dy -= 1;
                    passVertical[dy][dx] = true;
                }
            }

            else if (tmp == 'D'){
                if (dy + 1 < n){
                    passVertical[dy][dx] = true;
                    dy += 1;
                    passVertical[dy][dx] = true;
                }
            }

            else if (tmp == 'L'){
                if (dx - 1 >= 0){
                    passHorizontal[dy][dx] = true;
                    dx -= 1;
                    passHorizontal[dy][dx] = true;
                }
            }

            else if (tmp == 'R'){
                if (dx + 1 < n){
                    passHorizontal[dy][dx] = true;
                    dx += 1;
                    passHorizontal[dy][dx] = true;
                }
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (passVertical[i][j] && passHorizontal[i][j]) System.out.print('+');
                else if (passVertical[i][j]) System.out.print('|');
                else if (passHorizontal[i][j]) System.out.print('-');
                else System.out.print('.');
            }
            System.out.println();
        }
    }
}
