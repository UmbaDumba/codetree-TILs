#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    vector<vector<int>> maps(n, vector<int>(m, 0));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> maps[i][j];
        }
    }

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    queue<vector<int>> que;
    que.push({0, 0, 0});

    while(!que.empty()){
        int x = que.front()[0];
        int y = que.front()[1];
        int dis = que.front()[2];
        que.pop();

        if(x == n-1 && y == m-1){
            cout << dis;
            return 0;
        }
        
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                continue;
            }
            if(maps[nx][ny] == 1){
                maps[nx][ny] = 0;
                que.push({nx, ny, dis+1});
            }
        }

    }

    cout << "-1";

    return 0;
}