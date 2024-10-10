#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }

    vector<int> dp(n, 1);

    dp[0] = 1;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(nums[i] < nums[j]){
                // 뒤에 붙일 수 있음
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}