#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    cin >> n;

    vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(3, vector<long long>(3, 0)));
    // [i][j][k] : i번째날, j개의 t, k개의 연속된 b 경우의수


    // 0번째날은 1로 고정
    dp[0][0][0] = 1;
    for(int i = 1; i<=n; i++){
        // g를 받은경우 -> 이전날에 뭘 받았든간에 다 가능함
        // t의 개수는 변화가 없고
        // 연속b의 개수는 0으로 초기화됨
        for(int j = 0; j<3; j++){
            for(int k = 0; k<3; k++){
                dp[i][j][0] += dp[i-1][j][k];
            }
        }

        // b를 받은경우 -> dp[i-1][j][2] 상황에서만 불가능
        // b개수에 변화가 있음 (1씩 추가)
        for(int j = 0; j<3; j++){
            for(int k = 0; k<2; k++){
                dp[i][j][k+1] += dp[i-1][j][k];
            }
        }

        // t를 받은경우 -> dp[i-1][2][k] 상황에서만 불가능
        // t 개수에 변화가 있음 (1추가)
        // 연속b개수는 0으로 초기화됨
        for(int j = 0; j<2; j++){
            for(int k = 0; k<3; k++){
                dp[i][j+1][0] += dp[i-1][j][k];
            }
        }
    }

    long long answer = 0;

    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            answer += dp[n][i][j];
            answer %= ((10*10*10*10*10*10*10*10*10) + 7);
        }
    }

    cout << answer;

    return 0;
}