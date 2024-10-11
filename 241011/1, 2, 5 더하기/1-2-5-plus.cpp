#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>> n;

    vector<int> dp(n+1, 0);
    vector<int> num125 = {1,2,5};
    dp[0] = 1;

    for(int i = 1; i <=n; i++){
        for(int j = 0; j<3; j++){
            if(i < num125[j]){
                continue;
            }
            dp[i] += dp[i-num125[j]];
            dp[i] %= 10007;
        }
    }

    cout << dp[n];

    return 0;
}