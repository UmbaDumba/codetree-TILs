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
    *(lens) = max(*(lens), dfslens);
    for(int i = 0; i<4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(newx < 0 || newx >= n || newy < 0 || newy >= n){
            continue;
        }
        if(nums[x][y] < nums[newx][newy]){
            if(dp[newx][newy] != 0){
                // 최대 길이가 이미 구해진 부분
                // 여기서부터는 또 탐색할필요가 없다!
                dfslens += dp[newx][newy];
                *(lens) = max(*(lens), dfslens);
                return;
            }
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