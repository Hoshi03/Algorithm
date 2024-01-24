import java.util.*;

public class Main {

    public static String solution(String s1, String s2){

        String res = "";

        int h1,h2,m1,m2,sec1,sec2,h3,m3,sec3;

        h1 = Integer.parseInt(s1.substring(0,2));
        m1 = Integer.parseInt(s1.substring(3,5));
        sec1 = Integer.parseInt(s1.substring(6,8));
        h2 = Integer.parseInt(s2.substring(0,2));
        m2 = Integer.parseInt(s2.substring(3,5));
        sec2 = Integer.parseInt(s2.substring(6,8));

        sec3 = sec2 - sec1;

        if (s1.equals(s2)) return "24:00:00";

        if (sec3 < 0){
            sec3 += 60;
            m2 -= 1;
        }

        m3 = m2 - m1;

        if (m3 < 0){
            m3 += 60;
            h2 -= 1;
        }

        h3 = h2 - h1;

        if (h3 < 0){
            h3 += 24;
        }

        if (h3 < 10) res += '0'+ String.valueOf(h3) + ":";
        else res += String.valueOf(h3) + ":";

        if (m3 < 10) res += '0'+ String.valueOf(m3) + ":";
        else res += String.valueOf(m3) + ":";

        if (sec3 < 10) res += '0'+ String.valueOf(sec3);
        else res += String.valueOf(sec3);


        return res;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String s1 = in.nextLine();
        String s2 = in.nextLine();
        System.out.println(solution(s1,s2));
    }
}
