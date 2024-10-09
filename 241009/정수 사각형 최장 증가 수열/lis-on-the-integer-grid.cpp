#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> nums;
vector<vector<int>> dp;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

void dfs(int x, int y, int dfslens, int* lens){

    if(dp[x][y] != 0){
        // 이미 최대길이가 구해진 시작점
        // -> dp에 저장되어 있는값을 그대로 사용해준다
        dfslens += (dp[x][y] - 1);
        *(lens) = max(*(lens), dfslens);
        return; // 반복필요없음
    }

    *(lens) = max(*(lens), dfslens);
    for(int i = 0; i<4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(newx < 0 || newx >= n || newy < 0 || newy >= n){
            continue;
        }
        if(nums[x][y] < nums[newx][newy]){
            dfs(newx, newy, dfslens+1, lens);
        }
    }
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
            int lens = 0;
            // dfs -> 최대길이를 lens에 담아오기
            dfs(i, j, 1, &lens);
            dp[i][j] = lens;
        }
    }

    int result = 0;
    for(int i = 0; i<n; i++){
        result = max(result, *max_element(dp[i].begin(), dp[i].end()));
    }

    cout << result;

    
    return 0;
}