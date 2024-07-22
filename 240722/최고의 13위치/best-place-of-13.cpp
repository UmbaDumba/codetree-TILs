#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<vector<int>> arrays(n, vector<int>(n,0));
    vector<vector<int>> oneindex;
    for(int i = 0; i<n; i++){
        vector<int> lines;
        for(int j = 0; j<n; j++){
            int temp;
            cin >> temp;
            arrays[i][j] = temp;
            if(temp == 1){
                oneindex.push_back({i,j});
            }
        }
    }

    int max = 0;

    for(int i = 0; i<oneindex.size(); i++){
        int a = oneindex[i][0];
        int b = oneindex[i][1];
        int ones = 0;
        for(int j = 0; j<3; j++){
            if(b+j >= n){
                continue;
            }
            if(arrays[a][b+j] == 1){
                ones++;
            }
        }
        if(ones > max){
            max = ones;
        }
        if(max == 3){
            // 이미 최대값
            cout << max << endl;
            return 0;
        }
    }
    cout << max << endl;

    
    return 0;
}