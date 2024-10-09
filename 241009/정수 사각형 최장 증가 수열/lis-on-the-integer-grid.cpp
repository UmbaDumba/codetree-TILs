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

    int max_len = 1;
    for(int i = 0; i<4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(newx < 0 || newx >= n || newy < 0 || newy >= n){
            continue;
        }
        if(nums[x][y] < nums[newx][newy]){
            max_len = max(dfs(newx, newy) + 1, max_len);
        }
    }
    return max_len;
}


int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;
    nums = vector<vector<int>>(n, vector<int>(n, 0));
    dp = vector<vector<int>>(n, vector<int>(n, 0));


    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> nums[i][j];
        }
    }



    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            dp[i][j] = dfs(i, j);
        }
    }

    int result = 0;
    for(int i = 0; i<n; i++){
        result = max(result, *max_element(dp[i].begin(), dp[i].end()));
    }

    cout << result;

    
    return 0;
}