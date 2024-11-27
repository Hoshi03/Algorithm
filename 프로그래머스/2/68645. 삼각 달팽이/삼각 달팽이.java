import java.util.*;

class Solution {
    static int[][] dir = {{1, 0}, {0, 1}, {-1, -1}}; // 아래, 오른쪽, 왼쪽 위 방향
    
    public ArrayList<Integer> solution(int n) {
        int[][] arr = new int[n][n];
        
        int y = 0, x = 0; // 시작 위치
        int num = 1;      // 채울 숫자
        int cnt = 0;      // 방향 인덱스
        int move = 0;     // 잘못된 움직임 카운트
        
        arr[0][0] = num++; // 첫 번째 숫자 설정
        
        while (true) {
            if (move > 2) break; // 잘못된 움직임이 3번 연속되면 종료
            
            // 다음 위치 계산
            int dy = y + dir[cnt][0];
            int dx = x + dir[cnt][1];
            
            // 이동 가능 여부 확인
            if (dy < 0 || dy >= n || dx < 0 || dx >= n || arr[dy][dx] != 0) {
                cnt = (cnt + 1) % 3; // 방향 전환
                move++;              // 잘못된 움직임 카운트 증가
            } else {
                y = dy;              // 위치 갱신
                x = dx;
                arr[y][x] = num++;   // 숫자 채우기
                move = 0;            // 잘못된 움직임 초기화
            }
        }
        
        // 결과 리스트 생성
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) { // 삼각형 형태만 탐색
                ans.add(arr[i][j]);
            }
        }
        
        return ans;
    }
}
