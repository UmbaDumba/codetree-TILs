#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> maps(n, vector<int>(m, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> maps[i][j];
        }
    }

    queue<vector<int>> myque;
    myque.push({0,0});
    maps[0][0] = -1;
    while(!(myque.empty())){
        vector<int> nowi = myque.front();
        if((nowi[0] == (n-1)) && (nowi[1] == (m-1))){
            cout << "1";
            return 0;
        }
        myque.pop();
        vector<int> dx = {1, 0,-1,0};
        vector<int> dy = {0, 1, 0, -1};
        for(int i = 0; i<4; i++){
            int newx = nowi[0] + dx[i];
            int newy = nowi[1] + dy[i];
            if(newx < 0 || newx >= n || newy < 0 || newy >= m){
                continue;
            }
            if(maps[newx][newy] == 1){
                maps[newx][newy] = -1;
                myque.push({newx, newy});
            }
        }
    }

    cout << "0";
    return 0;
}