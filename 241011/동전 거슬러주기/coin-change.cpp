#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<int> coins;
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }

    sort(coins.begin(), coins.end());

    vector<int> dp(m+1, INT_MAX);

    for(int i = 0; i<n; i++){
        dp[coins[i]] = 1;
    }// 딱 맞는 코인 한개만 쓰는게 이득

    for(int i = coins[0]+1; i<= m; i++){
        for(int j = 1; j<i; j++){
            if(dp[j] == INT_MAX || dp[i-j] == INT_MAX){
                continue;
            }
            dp[i] = min(dp[i], dp[j] + dp[i-j]);
        }
    }
    if(dp[m] == INT_MAX){
        dp[m] = -1;
    }
    cout << dp[m];

    return 0;
}