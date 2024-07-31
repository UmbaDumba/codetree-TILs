#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> step(vector<vector<int>> maps, int x, int y){
    int num = maps[x][y];
    int nextx = -1;
    int nexty = -1;
    int maxnum = 0;
    for(int i = 0; i<maps.size(); i++){
        for(int j = 0; j<maps.size(); j++){
            if(maps[i][j] > maxnum && maps[i][j] < num){
                nextx = i;
                nexty = j;
                maxnum = maps[i][j];
            }
        }
    }
    return {nextx, nexty};
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    vector<vector<int>> maps(n, vector<int>(n, 0));
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n; j++){
            cin >> maps[i][j];
        }
    }

    int x, y;
    cin >> x >> y;

    vector<int> prev = {x-1, y-1};

    for(int i = 0; i<k; i++){
        vector<int> next = step(maps, prev[0], prev[1]);
        if(next[0] == -1){
            break;
        }
        prev = next;
    }

    cout << prev[0] + 1 << " "<<prev[1] + 1;

    return 0;
}