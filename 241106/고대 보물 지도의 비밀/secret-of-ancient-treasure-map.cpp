#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    vector<long long> nums(n, 0);
    vector<vector<long long>> dp(n, vector<long long>(k+1, LONG_MIN));

    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }

    if(nums[0] < 0){
        dp[0][1] = nums[0];
    }else{
        dp[0][0] = nums[0];
    }

    for(int i = 1; i<n; i++){
        
        if(nums[i] < 0){
            // 음수일 때
            // 바로 이전꺼에 붙이거나
            // 나 혼자 시작하거나 둘 중 하나임
            // 다시 시작의 경우 dp[i][1]로 들어가야함

            // 바로 이전 뒤에 붙이는상황
            for(int j = 0; j<k; j++){
                if(dp[i-1][j] == LONG_MIN){
                    // 여기까지 안온다는것 == 못붙인다!
                    continue;
                }
                dp[i][j+1] = dp[i-1][j] + nums[i];
            }

            // 다시 시작하는 상황
            dp[i][1] = max(dp[i][1], nums[i]);
        }else{
            // 양수일 때
            // 그냥 무조건 붙여주거나, dp[i][0]에서 다시 시작한다
            for(int j = 0; j<=k; j++){
                if(dp[i-1][j] == LONG_MIN){
                    // 여기까지 안온다는것 == 못붙인다!
                    continue;
                }
                dp[i][j] = dp[i-1][j] + nums[i];
            }

            // 다시 시작하려는것
            dp[i][0] = max(dp[i][0], nums[i]);
        }
        
    }

    long long answer = INT_MIN;
    for(int i = 0; i<n; i++){
        answer = max(answer, *max_element(dp[i].begin(), dp[i].end()));
        
    }

    cout << answer;

    return 0;
}