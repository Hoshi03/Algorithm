import java.util.*;
import java.io.*;

class Main {
    static char[][] arr;
    static int n;

    public static int getMax() {
        int maxCount = 0;
        for (int i = 0; i < n; i++) {
            int count = 1;
            for (int j = 1; j < n; j++) {
                if (arr[i][j] == arr[i][j - 1]) count++;
                else {
                    maxCount = Math.max(maxCount, count);
                    count = 1;
                }
            }
            maxCount = Math.max(maxCount, count);
        }

        for (int i = 0; i < n; i++) {
            int count = 1;
            for (int j = 1; j < n; j++) {
                if (arr[j][i] == arr[j - 1][i]) count++;
                else {
                    maxCount = Math.max(maxCount, count);
                    count = 1;
                }
            }
            maxCount = Math.max(maxCount, count);
        }
        return maxCount;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        arr = new char[n][n];

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < n; j++) {
                arr[i][j] = s.charAt(j);
            }
        }

        int res = getMax();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j + 1 < n && arr[i][j] != arr[i][j + 1]) {
                    swap(i, j, i, j + 1);
                    res = Math.max(res, getMax());
                    swap(i, j, i, j + 1); 
                }

                if (i + 1 < n && arr[i][j] != arr[i + 1][j]) {
                    swap(i, j, i + 1, j);
                    res = Math.max(res, getMax());
                    swap(i, j, i + 1, j);
                }
            }
        }
        System.out.println(res);
    }

    public static void swap(int x1, int y1, int x2, int y2) {
        char temp = arr[x1][y1];
        arr[x1][y1] = arr[x2][y2];
        arr[x2][y2] = temp;
    }
}