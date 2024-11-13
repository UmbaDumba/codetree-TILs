#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 100
#define MAX_M 10000

using namespace std;

// dp[i][j] : 지금까지 i번째 보석까지 고려해봤고,
//            지금까지 고른 보석 무게의 합이 j였을 때 
//            얻을 수 있는 최대 가치
int dp[MAX_N + 1][MAX_M + 1];

int n, m;

int weight[MAX_N + 1], value[MAX_N + 1];

void Initialize() {
    // 최대를 구하는 문제이므로, 
    // 초기에는 전부 INT_MIN을 넣어줍니다.
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            dp[i][j] = INT_MIN;
    
    // 초기 조건으로
    // 아직 아무런 보석도 고려해보지 않은 상태를 정의합니다.
    // 따라서 지금까지 0번째 보석까지 고려해봤고,
    // 지금까지 고른 보석 무게의 합이 0이었을 때
    // 가치를 0만큼 얻었으므로
    // dp[0][0] = 0을 초기 조건으로 설정합니다.
    dp[0][0] = 0;
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        cin >> weight[i] >> value[i];

    Initialize();

    // 지금까지 i번째 보석까지 고려해봤고,
    // 지금까지 고른 보석 무게의 합이 j였을 때 
    // 얻을 수 있는 최대 가치를 계산합니다.
    for(int i = 1; i <= n; i++){
        // 이런 상황을 만들기 위한 선택지는 크게 2개 입니다.
        

        for(int j = 0; j <= m; j++) {
            // j >= weight[i]인 경우에는 Case 1, Case 2 중 더 좋은 값을 선택합니다.
            if(j >= weight[i])
                dp[i][j] = max(dp[i - 1][j - weight[i]] + value[i], dp[i - 1][j]);
            
            // j < weight[i]인 경우에는, Case 2만 가능합니다.
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    // n개의 보석까지 전부 고려해봤을 때
    // 무게의 합이 m을 넘지 않는 경우를 전부 조사하여
    // 그 중 최댓값을 선택합니다.

    int ans = 0;

    for(int j = 0; j <= m; j++)
        ans = max(ans, dp[n][j]);

    cout << ans;
}