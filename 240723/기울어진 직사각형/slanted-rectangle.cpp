#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int round_map(vector<vector<int>> maps, vector<int> start){
    int a = start[0];
    int b = start[1];
    // 왼쪽 위로 가는것, 오른쪽 위로 가는것 => 결정되면, 왼쪽 아래로 내려가는건 자동결정!
    // 왼쪽이든 오른쪽이든 많이가는게 이득일것같음
    int n = maps.size();
    int max_leftup = min(a, b);
    if(a - max_leftup == 0){
        max_leftup--;
    }
    int max_rightup = min(a, n-1-b);
    if(a - max_rightup == 0){
        max_rightup--;
    }

    vector<vector<int>> steps = {
        {-1, 1, max_rightup},
        {-1, -1, max_leftup},
        {1, -1, max_rightup},
        {1, 1, max_leftup}
    };

    int result = 0;

    for(int i = 0; i<4; i++){
        for(int j = 0; j<steps[i][2]; j++){
            a+=steps[i][0];
            b+=steps[i][1];
            if(a < 0 || a >= n || b < 0 || b >= n){
                return 0;
            }
            result+=maps[a][b];
        }
    }

    return result;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<vector<int>> checkers(n, vector<int>(n, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int temp;
            cin >> temp;
            checkers[i][j] = temp;
        }
    }

    int maxresult = 0;

    for(int i = n-1; i>1; i--){
        for(int j = 1; j<n-1; j++){
            maxresult = max(maxresult, round_map(checkers, {i, j}));
        }
    }

    cout << maxresult << endl;

    return 0;
}