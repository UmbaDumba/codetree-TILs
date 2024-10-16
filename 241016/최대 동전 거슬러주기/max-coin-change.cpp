#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n, m;
    cin >> n >> m;
    vector<int> coins;
    vector<int> dp(m+1, -1);
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        coins.push_back(temp);
        dp[temp] = 1;
    }

    dp[0] = 0;
    for(int i = 1; i<=m; i++){
        for(int j = 0; j<=i; j++){
            dp[i] = max(dp[i], dp[j] + dp[i-j]);
        }
    }

    cout << dp[m];

    return 0;
}