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
    dp[0][n-1] = nums[0][n-1];
    for(int i = n-2; i>=0; i--){
        dp[0][i] = dp[0][i+1] + nums[0][i];
    }
    for(int i = 1; i<n; i++){
        dp[i][n-1] = dp[i-1][n-1] + nums[i][n-1];
    }

    for(int i = 1; i<n; i++){
        for(int j = n-2; j>=0; j--){
            dp[i][j] = nums[i][j] + min(dp[i-1][j], dp[i][j+1]);
        }
    }

    cout << dp[n-1][0];

    return 0;
}