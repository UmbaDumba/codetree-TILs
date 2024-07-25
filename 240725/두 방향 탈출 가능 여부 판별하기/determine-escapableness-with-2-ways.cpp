#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> maps, int x, int y, bool *ends){
    
    vector<int> dx = {1, 0};
    vector<int> dy = {0, 1};
    for(int i = 0; i<2; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(newx >= maps.size() || newy >= maps[0].size()){
            continue;
        }
        if((newx == (maps.size()-1)) && (newy == (maps[0].size()-1))){
            // 끝에 도달
            (*ends) = true;
            return;
        }
        if(maps[newx][newy] == 1){
            maps[newx][newy] = -1; // 이미 지나간곳
            dfs(maps, newx, newy, ends);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maps(n, vector<int>(m,0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> maps[i][j];
        }
    }

    bool ends = false;
    dfs(maps, 0, 0, &ends);
    cout << ends << endl;

    return 0;
}