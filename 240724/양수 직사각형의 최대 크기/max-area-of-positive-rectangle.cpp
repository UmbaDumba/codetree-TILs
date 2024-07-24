#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maps(n, vector<int>(m, 0));
    vector<vector<int>> down_maps(n, vector<int>(m, 0));
    bool flag = true;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int temp;
            cin >> temp;
            maps[i][j] = temp;
            if(temp > 0){
                flag = false;
            }
        }
    }
    if(flag){
        // 양수가 하나도 없음
        cout << "-1"<<endl;
        return 0;
    }

    // 전처리
    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            if(maps[i][j] > 0){
                if(i+1 >= n){
                    down_maps[i][j] = 1;
                }else{
                    down_maps[i][j] = 1 + down_maps[i+1][j];
                }
            }
        }
    }

    // 탐색
    int maxsize = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int downmin = INT_MAX;
            for(int k = 0; k<m; k++){
                downmin = min(downmin, down_maps[i][k]);
                maxsize = max(maxsize, (k-i+1) * (downmin));
            }
        }
    }

    cout << maxsize<<endl;


    return 0;
}