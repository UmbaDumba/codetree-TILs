#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>> maps, int x, int y, int n, int m){
    if((x == (n-1)) && (y == (m-1))){
        // 끝에 도달
        return true;
    }

    //maps[x][y] = 0;
    vector<int> dx = {1, 0};
    vector<int> dy = {0, 1};

    for(int i = 0; i<2; i++){
        
        int newx = x + dx[i];
        int newy = y + dy[i];
        if((newx >= n) || (newy >= m)){
            continue;
        }
        if(maps[newx][newy] == 1){
            maps[newx][newy] = 0;
            return dfs(maps, newx, newy, n, m);
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
        cout << "1"<<endl;
        return 0;
    }

    maps[0][0] = -1;
    cout << dfs(maps, 0, 0, n, m) << endl;

    return 0;
}