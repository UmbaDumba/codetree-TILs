#include <iostream>
#include <vector>
using namespace std;



int main() {
    // 여기에 코드를 작성해주세요.
    
    int n;
    cin >> n;

    vector<long long> dp(n+1, 0);

    dp[1] = 0;
    if(n == 2){
        cout << 1;
        return 0;
    }
    dp[2] = 1;
    if(n == 3){
        cout << 1;
        return 0;
    }
    dp[3] = 1;

    

    for(int i = 4; i<=n; i++){
        dp[i] = (dp[i-2] + dp[i-3]) % 10007;
        // 최종적으로 2칸뛰어서 도착 + 최종적으로 3칸뛰어서 도착
    }

    cout << dp[n];

    
    return 0;
}