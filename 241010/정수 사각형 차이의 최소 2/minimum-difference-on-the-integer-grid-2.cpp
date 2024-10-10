#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> nums[i][j];
        }
    }


    int result = INT_MAX;
    for(int test_min = 1; test_min<=100; test_min++){
        

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(nums[i][j] < test_min){
                    // test_min보다 큰애들만 있어야함! (test_min을 최소값으로 고정)
                   nums[i][j] = INT_MAX;
                }
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                dp[i][j] = INT_MAX;
            }
        }

        dp[0][0] = nums[0][0];
        for(int i = 1; i<n; i++){
            dp[i][0] = max(dp[i-1][0], nums[i][0]);
        }
        for(int i = 1; i<n; i++){
            dp[0][i] = max(dp[0][i-1], nums[0][i]);
        }
       
        for(int i = 1; i<n; i++){
            for(int j = 1; j<n; j++){
                dp[i][j] = max(min(dp[i-1][j], dp[i][j-1]), nums[i][j]);
            }
        }

        if(dp[n-1][n-1] == INT_MAX){
            // test_min을 최소로 만드는 경로가 하나도 없는것!
            continue;
        }

        result = min(result, (dp[n-1][n-1] - test_min));
    }
    cout << result;

    return 0;
}