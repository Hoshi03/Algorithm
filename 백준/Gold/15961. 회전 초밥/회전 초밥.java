import java.util.*;

class Main
{
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int D = sc.nextInt();
        int K = sc.nextInt();
        int C = sc.nextInt();

        int[] dish = new int[N];
        for (int i = 0; i < N; i++)
            dish[i] = sc.nextInt();

        int[] dishCount = new int[D + 1];
        int res = 0;
        for (int i = 0; i < K - 1; i++)
            if (dishCount[dish[i]]++ == 0)
                res++;

        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (dishCount[dish[(i + K - 1) % N]]++ == 0) res++;
            if (dishCount[C] == 0) res++; //쿠폰으로 먹는 초밥은 연결되지 않아도 된다, 여기서 추가하고 나중에 다시 빼자
            ans = Math.max(ans, res);
            if (dishCount[C] == 0) res--; //쿠폰으로 먹은 초밥이 있으면 다시 빼주기
            if (--dishCount[dish[i]] == 0) res--;
        }
        System.out.println(ans);
    }
}