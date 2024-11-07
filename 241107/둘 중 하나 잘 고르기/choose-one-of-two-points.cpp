#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0)); // 빨간색개수와 파란색 개수를 index로

    for(int i = 0; i<(2*n); i++){
        int redcard, bluecard;
        cin >> redcard >> bluecard;

        // i번째 시행일 때 == 지금 받은 카드를 가지기 전까지 가지고있던 카드개수가 i개
        // -> 즉 dp배열의 [0][i] ... [i][0] 까지를 확인 (x + y = i 인 인덱스들)
        // 저기에 빨간색을 선택한것과 파란색을 선택한것을 dp에 넣어준다.
        // 빨간색을 선택하면 x를 1증가
        // 파란색을 선택하면 y를 1증가

        for(int j = 0; j<=i; j++){
            if((j > n) || ((i-j) > n)){
                continue;
            }
            dp[j+1][i-j] = max(dp[j][i-j] + redcard, dp[j+1][i-j]);
        
            dp[j][i-j+1] = max(dp[j][i-j] + bluecard, dp[j][i-j+1]);
            
        }

    }

    cout << dp[n][n];




    return 0;
}