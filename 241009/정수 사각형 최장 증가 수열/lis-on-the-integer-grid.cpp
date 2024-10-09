#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 1));

    int x, y, max_ele;
    max_ele = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> nums[i][j];
            if(nums[i][j] > max_ele){
                x = i;
                y = j;
                max_ele = nums[i][j];
            }
        }
    }

    queue<pair<int, int>> que;
    que.push({x, y});

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    while(!que.empty()){
        pair<int, int> index = que.front();
        que.pop();
        for(int i = 0; i<4; i++){
            int newx = index.first + dx[i];
            int newy = index.second + dy[i];
            if(newx >= n || newx < 0 || newy >= n || newy < 0){
                continue;
            }
            if(nums[newx][newy] < nums[index.first][index.second]){
                // 이동가능
                dp[newx][newy] = dp[index.first][index.second] + 1;
                que.push({newx, newy});
            }
        }
    }


    int result = 0;
    for(int i = 0; i<n; i++){
        result = max(*max_element(dp[i].begin(), dp[i].end()), result);
    }
    
    cout << result;

    return 0;
}