#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<vector<int>> arrays(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i= 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> arrays[i][j];
        }
    }

    dp[0][0] = arrays[0][0];

    for(int i = 1; i<n; i++){
        dp[0][i] = arrays[0][i] + dp[0][i-1];
        dp[i][0] = arrays[i][0] + dp[i-1][0];
    }

    

    for(int i = 1; i<n; i++){
        for(int j = 1; j<n; j++){
            dp[i][j] = max(dp[i-1][j] + arrays[i][j], dp[i][j-1] + arrays[i][j]);
        }
    }

    cout << *max_element(dp[n-1].begin(), dp[n-1].end());

    return 0;
}