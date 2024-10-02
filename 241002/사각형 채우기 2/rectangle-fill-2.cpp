#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<long long> dp(n+1, 0);

    dp[1] = 1;
    if(n >= 2){
        dp[2] = 3;
    }else{
        cout << dp[n];
        return 0;
    }

    for(int i = 3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2] * 2) % 10007;
    }

    cout << dp[n];

    return 0;
}