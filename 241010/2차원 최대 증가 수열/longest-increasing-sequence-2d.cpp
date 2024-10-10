#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m, 0));
    vector<vector<int>> dp(n, vector<int>(m, 0)); // dp[i][j]가 마지막 발판일 때 최대
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> nums[i][j];
        }
    }

    dp[0][0] = 1;

    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(nums[i][j] > nums[0][0]){
                dp[i][j] = 2; // [0][0]과 이동한곳
            }
        }
    }
    // [0][0]에서 점프 한번으로 갈 수 있는곳

    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(dp[i][j] == 0){
                //[0][0] 에서 출발해서는 어짜피 도달 못하는곳
                continue;
            }
            // [i][j]에서, 점프하는게 좋은지 아닌지 확인하면서 업데이트
            // 한칸 이상부터 확인해야함
            for(int k = i+1; k<n; k++){
                for(int l = j+1; l<m; l++){
                    if(nums[i][j] < nums[k][l]){
                        // 점프할 수 있음
                        dp[k][l] = max(dp[k][l], dp[i][j] + 1);
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i<n; i++){
        ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
    }

    cout << ans;

    return 0;
}