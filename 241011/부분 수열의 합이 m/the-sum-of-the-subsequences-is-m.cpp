#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<int> nums;
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    vector<int> dp(m+1, 101);

    dp[0] = 0;

    for(int i = 0; i<n; i++){
        // nums[i] 로 테스트 해보기
        for(int j = m; j>=0; j--){
            if(nums[i] > j){
                continue;
            }
            dp[j] = min(dp[j], 1 + dp[j-nums[i]]);
        }
    }

    if(dp[m] == 101){
        dp[m] = -1;
    }
    cout << dp[m];

    return 0;
}