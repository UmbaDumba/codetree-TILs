#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    vector<int> dp(n, 0); // nums[i]를 꼭 마지막에 포함하는 수열 길이

    dp[0] = 1; // 자기자신만 포함가능
    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(nums[i] > nums[j]){
                // 뒤에 붙일 수 있음
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    cout << dp[n-1];

    return 0;
}