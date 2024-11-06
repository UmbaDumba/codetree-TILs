#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    cin >> n;
    vector<int> nums(n, 0);
    vector<int> dp(n, 0);
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }

    dp[0] = nums[0];
    
    for(int i = 1; i<n; i++){
        dp[i] = max(nums[i], dp[i-1] + nums[i]);
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}