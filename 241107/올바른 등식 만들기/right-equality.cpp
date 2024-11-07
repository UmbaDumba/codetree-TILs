#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<int> nums(n, 0);
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(41, 0));
    // 무조건 20을 더해서 양수로 만들기 (index로 관리하기 때문)
    // 즉,, 실제 계산결과가 13이었다면, index로 관리할때는 23으로 관리
    // 이렇게 되면 실제 계산결과가 -20일 때 index 0으로 표현 가능해진다!
    // -21부터는 index가 0보다 작아지므로 불가능
    // m의 범위또한 20까지이므로, dp배열또한 40까지만 가능함!
    // 해당 숫자까지 올 수 있는 경우의수를 저장해준다.
    // 0인경우, 불가능한것!


    if(nums[0] <= 20){
        dp[0][20+nums[0]] += 1;
    }
    if(nums[0] >= -20){
        dp[0][20-nums[0]] += 1;
    }
    

    // 여기서부터는 이미 20이 더해진채로 시작되는것 == 범위를 0~40으로 생각하기 
    for(int i = 1; i<n; i++){
        for(int j = 0; j<41; j++){
            if(dp[i-1][j] == 0){
                continue;
            }
            if((j + nums[i]) < 41){
                dp[i][j+nums[i]] += dp[i-1][j];
            }
            if((j - nums[i]) >= 0){
                dp[i][j-nums[i]] += dp[i-1][j];
            }
        }
    }

    cout << dp[n-1][m+20];


    return 0;
}