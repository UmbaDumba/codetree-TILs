#include <iostream>
#include <vector>
using namespace std;

int howmoney(vector<vector<int>> arrays, vector<int> index){
    int a = index[0];
    int b = index[1];
    int moneys = 0;
    for(int i = a; i<a+3; i++){
        for(int j = b; j<b+3; j++){
            if(arrays[i][j] == 1){
                moneys++;
            }
        }
    }
    return moneys;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<vector<int>> arrays(n, vector<int>(n,0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int temp;
            cin >> temp;
            arrays[i][j] = temp;
        }
    }

    int max = 0;
    for(int i = 0; i<n-2; i++){
        for(int j = 0; j<n-2; j++){
            int moneys = howmoney(arrays, {i, j});
            if(max < moneys){
                max = moneys;
            }
        }
    }

    cout << max << endl;

    return 0;
}