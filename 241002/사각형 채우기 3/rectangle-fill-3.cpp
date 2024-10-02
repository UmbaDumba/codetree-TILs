#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<long long> dp(n+1, 0);

    dp[0] = 1;
    dp[1] = 2;
    if(n >= 2){
        dp[2] = 7;
    }else{
        cout << dp[n];
        return 0;
    }

    if(n >= 3){
        dp[3] = 22;
    }else{
        cout << dp[n];
        return 0;
    }

    for(int i = 4; i<=n; i++){
        
        dp[i] = ((dp[i-1] * 3) + (dp[i-2] + 1000000007) - dp[i-3]) % 1000000007;
        
        
    }


    cout << dp[n];

    return 0;
}