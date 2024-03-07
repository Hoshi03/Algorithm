import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        TreeSet<String> res = new TreeSet<>();

        for (int i = 0; i < n; i++){
            String name = in.next();
            String state = in.next();
            if (state.equals("enter")) res.add(name);
            else res.remove(name);
        }

        String[] result = res.toArray(res.toArray(new String[res.size()]));
        Arrays.sort(result, Collections.reverseOrder());

        for (String x : result) System.out.println(x);
    }
}