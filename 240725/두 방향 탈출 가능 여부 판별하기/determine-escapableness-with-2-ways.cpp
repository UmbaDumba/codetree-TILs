#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>> maps, int x, int y){
    
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
            return true;
        }
        if(maps[newx][newy] == 1){
            maps[newx][newy] = -1; // 이미 지나간곳
            if(dfs(maps, newx, newy)){
                return true;
            }
        }
    }
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    bool all_1 = true;
    vector<vector<int>> maps(n, vector<int>(m,0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> maps[i][j];
            if(maps[i][j] == 0){
                all_1 = false;
            }
        }
    }
    if(all_1){
        cout << "0"<<endl;
        return 0;
    }

    
    cout << dfs(maps, 0, 0) << endl;

    return 0;
}