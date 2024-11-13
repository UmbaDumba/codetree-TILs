#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 100
#define MAX_M 100000

using namespace std;

// 변수 선언
int n, m;
int arr[MAX_N + 1];

// dp[i][j] : 지금까지 i번째 수까지만 고려해봤을 때,
//            고른 수의 합을 j로 만드는 것이 가능하면 true
//            불가능하면 false
bool dp[MAX_N + 1][MAX_M + 1];

void Initialize() {
    // 초기 조건으로
    // 아직 아무런 수도 고려해보지 않은 상태를 정의합니다.
    // 따라서 지금까지 0번째 수까지 고려해기에
    // 지금까지 선택한 수의 합이 0이므로
    // dp[0][0] = true가 됩니다.
    dp[0][0] = true;
}

int main() {
    // 입력:
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    
    // 만들 수 있는 최대 합 m을 계산합니다.
    for(int i = 1; i <= n; i++)
        m += arr[i];

    Initialize();

    // 지금까지 i번째 수까지 고려해봤고,
    // 지금까지 고른 수들의 합이 j가 되는게 가능한지를 판단합니다.
    for(int i = 1; i <= n; i++){
        // 이런 상황을 만들기 위한 선택지는 크게 2개 입니다.
        
        for(int j = 0; j <= m; j++) {
            // Case 1
            if(j >= arr[i] && dp[i - 1][j - arr[i]])
                dp[i][j] = true;
            
            // Case 2
            if(dp[i - 1][j])
                dp[i][j] = true;
        }
    }

    // n개의 수까지 전부 고려했을 때
    // 그룹 A에 대해 정확히 합 i를 만들 수 있다면,
    // i / m - i 이렇게 두 그룹으로 나눌 수 있다는 뜻이기에
    // 차이의 최솟값을 갱신합니다.
    int ans = INT_MAX;
    for(int i = 1; i < m; i++)
        if(dp[n][i])
            ans = min(ans, abs(i - (m - i)));

    cout << ans;
    return 0;
}