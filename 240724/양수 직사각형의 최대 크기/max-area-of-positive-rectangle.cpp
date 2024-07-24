#include <iostream>
#include <vector>
using namespace std;

bool is_pos(vector<vector<int>> maps, vector<int> left, vector<int> right){
    int x1 = left[0];
    int x2 = right[0];
    int y1 = left[1];
    int y2 = right[1];
    for(int i = x1; i<=x2; i++){
        for(int j = y1; j<=y2; j++){
            if(maps[i][j] <= 0){
                return false;
            }
        }
    }
    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maps(n, vector<int>(m, 0));
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

    int maxsize = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            // {i, j} 시작
            if(maps[i][j] <= 0){
                // 시작부터 조건에 안맞음
                continue;
            }
            for(int k = i; k<n; k++){
                for(int l = j; l<m; l++){
                    if(is_pos(maps, {i, j}, {k, l})){
                        maxsize = max(maxsize, (k-i+1) * (l - j + 1));
                    }
                }
            }
        }
    }

    cout << maxsize << endl;

    return 0;
}