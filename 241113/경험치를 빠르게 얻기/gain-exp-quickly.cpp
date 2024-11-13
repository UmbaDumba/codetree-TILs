#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_N 100
#define MAX_T 10000

using namespace std;

// 변수 선언
int n, m, t;
int exp[MAX_N + 1];
int runtime[MAX_N + 1];

// dp[i][j] : i번째 퀘스트까지 고려헀을 때
//            지금까지 퀘스트를 진행하는 데 걸리는 시간의 총 합이 j일 때
//            얻을 수 있었던 최대 경험치
int dp[MAX_N + 1][MAX_T + 1];

void Initialize() {
    // 최대를 구하는 문제이므로
    // INT_MIN을 초기값으로 넣어줍니다.
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= t; j++)
            dp[i][j] = INT_MIN;
    
    // 초기조건은
    // 아직 아무런 퀘스트도 고려해보지 않은 상태입니다.
    // 현재 0번째 퀘스트까지 고려헀을 때
    // 수행시간은 0이었고, 이때 경험치 0을 얻게 됩니다.
    dp[0][0] = 0;
}

int main() {
    // 입력:
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> exp[i] >> runtime[i];
    
    // 최대 수행시간을 계산합니다.
    for(int i = 1; i <= n; i++)
        t += runtime[i];

    Initialize();

    // 점화식에 따라
    // 값을 채워줍니다.
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= t; j++) {
            // Case 1. 현재 퀘스트를 진행하여
            //         수행시간의 총 합이 j가 되기 위해서는
            //         i - 1번째 퀘스트 까지 수행시간이 j - runtime[i]가 되어야 합니다.
            if(j - runtime[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - runtime[i]] + exp[i]);
            
            // Case 2. 현재 퀘스트를 진행하지 않고
            //         수행시간의 총 합이 j가 되기 위해서는
            //         i - 1번째 퀘스트 까지 수행시간이 j가 되어야 합니다.
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    int ans = INT_MAX;
    for(int j = 0; j <= t; j++)
        if(dp[n][j] >= m)
            ans = min(ans, j);
    
    // 불가능하다면
    // -1이 답이 됩니다.
    if(ans == INT_MAX)
        ans = -1;

    cout << ans;
    return 0;
}