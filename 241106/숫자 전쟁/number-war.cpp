#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> cards1(n, 0);
    vector<int> cards2(n, 0);
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    for(int i = 0; i<n; i++){
        cin >> cards1[i];
    }
    for(int i = 0; i<n; i++){
        cin >> cards2[i];
    }


    // 대결한다 -> 오른쪽 혹은 아래쪽, 혹은 대각선
    // 버린다 -> 오른쪽 아래 (대각선) 으로감
    // 지금 위치가 -1인경우 == 지금위치로 올 수 있는 경우의수가 없음
    dp[0][0] = 0;

    for(int i = 0; i<n; i++){ // cards1
        for(int j = 0; j<n; j++){ // cards2
            if(dp[i][j] == -1){
                continue;
            }
            // 대결하는 경우
            if(cards1[i] < cards2[j]){
                dp[i+1][j] = dp[i][j]; // cards2 입장임
            }else if(cards1[i] > cards2[j]){
                dp[i][j+1] = max(dp[i][j+1], dp[i][j] + cards2[j]);
            }else{
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
            }

            // 그냥 버리는경우
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);

        }
    }

    // dp[n][~] dp[~][n] 요 라인에 있는것중 최대값

    int answer = *max_element(dp[n].begin(), dp[n].end());
    for(int i = 0; i<=n; i++){
        answer = max(answer, dp[i][n]);
    }

    cout << answer;

    return 0;
}