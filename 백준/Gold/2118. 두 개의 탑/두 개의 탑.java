import java.util.Scanner;

class Main
{

    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr= new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            arr[i] = in.nextInt();
            sum += arr[i];
        }

        int idx = 0, dist  = 0, rdist = sum;
        int ans = 0;

        //반시계 <= 시계방향이 되는 거리를 구한다
        // 시계방향으로 계속 이동한다
        for (int i = 0; i < n; i++){
            while (dist < rdist){
                dist += arr[idx];
                rdist -= arr[idx];
                idx = (idx + 1) % n; // idx는 원형 상태니까 계속 돌면서 이동한다
            }
            
            //시계, 반시계 중에서 더 작은거 하나만 고르면 되는데
            //rdist가 dist보다 더 작아질 때 까지 뺏으니 rdist와 비교한다
            ans = Math.max(ans, rdist);

            // 루프가 끝나면 시계방향으로 한칸 이동
            dist -= arr[i];
            rdist += arr[i];
        }

        System.out.println(ans);
    }
}