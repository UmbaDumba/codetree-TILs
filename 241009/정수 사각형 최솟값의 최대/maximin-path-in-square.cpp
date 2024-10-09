#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> nums[i][j];
        }
    }

    dp[0][0] = nums[0][0];
    for(int i = 1; i<n; i++){
        dp[0][i] = min(dp[0][i-1], nums[0][i]);
        dp[i][0] = min(dp[i-1][0], nums[i][0]);
    }

    for(int i = 1; i<n; i++){
        for(int j = 1; j<n; j++){
            int min1 = min(dp[i-1][j], nums[i][j]);
            int min2 = min(dp[i][j-1], nums[i][j]);
            dp[i][j] = max(min1, min2);
        }
    }

    cout << dp[n-1][n-1];

    return 0;
}