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

    dp[0] = 0;
    for(int i = 1; i<=nums[0]; i++){
        if(i >= n){
            break;
        }
        dp[i] = 1;
    }
    // [0] 에서 한번점프해서 갈 수 있는 곳들


    for(int i = 1; i<n; i++){
        if(dp[i] == 0){
            // 여기까지 못옴
            // 여기까지 못온거면,, 뒤에도 짜피 못감
            break;
        }
        for(int j = 1; j<=nums[i]; j++){
            if((i + j) >= n){
                break;
            }
            dp[i + j] = max(dp[j], dp[i] + 1);
            // 지금 위치에서 점프해서 가는게 이득인지 확인
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}