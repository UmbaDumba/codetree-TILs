#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(n, 0));
    vector<vector<int>> dp_max(n, vector<int>(n, 0));
    vector<vector<int>> dp_min(n, vector<int>(n, 0));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> nums[i][j];
        }
    }

    dp_max[0][0] = nums[0][0];
    dp_min[0][0] = nums[0][0];

    for(int i = 1; i<n; i++){
        //----- y증가
        // 왼쪾에서 왔을때의 max, min
        dp_max[0][i] = max(dp_max[0][i-1], nums[0][i]);
        dp_min[0][i] = min(dp_min[0][i-1], nums[0][i]);
        
        ///------x증가
        // 위에서 왔을때의 max, min
        dp_max[i][0] = max(dp_max[i-1][0], nums[i][0]);
        dp_min[i][0] = min(dp_min[i-1][0], nums[i][0]);
    }

    for(int i = 1; i<n; i++){
        for(int j = 1; j<n; j++){
            // 위에서 왔을때
            int max1 = max(dp_max[i-1][j], nums[i][j]);
            int min1 = min(dp_min[i-1][j], nums[i][j]);
            // 왼쪽에서 왔을 때
            int max2 = max(dp_max[i][j-1], nums[i][j]);
            int min2 = min(dp_min[i][j-1], nums[i][j]);

            // |최댓값-최솟값|을 최소로 만드는 방향선택해서 업데이트
            int temp1 = max1 - min1;
            int temp2 = max2 - min2;
            if(temp1 <= temp2){
                dp_max[i][j] = max1;
                dp_min[i][j] = min1;
            }else{
                dp_max[i][j] = max2;
                dp_min[i][j] = min2;
            }
        }
    }


    cout << dp_max[n-1][n-1] - dp_min[n-1][n-1];


    return 0;
}