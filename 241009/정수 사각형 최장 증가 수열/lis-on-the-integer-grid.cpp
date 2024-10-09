#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> nums;
vector<vector<int>> dp;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

int dfs(int x, int y){

    if(dp[x][y] != 0){
        // 이미 최대길이가 구해진 시작점
        // -> dp에 저장되어 있는값을 그대로 사용해준다
        return dp[x][y];
    }

    dp[x][y] = 1;
    for(int i = 0; i<4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(newx < 0 || newx >= n || newy < 0 || newy >= n){
            continue;
        }
        if(nums[x][y] < nums[newx][newy]){
            dp[x][y] = max(dfs(newx, newy)+1, dp[x][y]);
        }
    }
    return dp[x][y];
}


int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    nums = vector<vector<int>>(n, vector<int>(n, 0));
    dp = vector<vector<int>>(n, vector<int>(n, 0));


    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> nums[i][j];
        }
    }


    int result = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            result = max(dfs(i, j), result);
        }
    }


    cout << result;

    
    return 0;
}