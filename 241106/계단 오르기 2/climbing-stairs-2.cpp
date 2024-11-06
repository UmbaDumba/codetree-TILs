#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    cin >> n;
    vector<int> nums(n+1, 0);
    vector<vector<int>> dp(n+1, vector<int>(4, 0));
    // 각 칸까지 올라오는데, 사용한 1칸점프의 개수를 인덱스로 (0, 1, 2, 3)
    // -1이면 그냥 없는것

    for(int i = 1; i<=n; i++){
        cin >> nums[i];
    }

    dp[0] = {0, -1, -1, -1};
    dp[1] = {-1, nums[1], -1, -1};
    dp[2] = {nums[2], -1, nums[1]+nums[1], -1};

    for(int i = 3; i<=n; i++){
        // 지금위치까지 한칸
        for(int j = 0; j<3; j++){
            if(dp[i-1][j] == -1){
                continue;
            }
            dp[i][j+1] = max(dp[i][j+1], dp[i-1][j] + nums[i]);
        }

        // 두칸
        for(int j = 0; j<4; j++){
            if(dp[i-2][j] == -1){
                continue;
            }
            dp[i][j] = max(dp[i][j], dp[i-2][j] + nums[i]);
        }

    }

    
    cout << *max_element(dp[n].begin(), dp[n].end());
    

    return 0;
}