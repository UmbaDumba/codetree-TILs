#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    vector<vector<int>> maps(n, vector<int>(n, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> maps[i][j];
        }
    }

    int answer = 0;
    for(int i = 0; i<k; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if(maps[x][y] != 0){
            continue;
        }

        queue<vector<int>> myque;
        myque.push({x, y});
        maps[x][y] = -1;
        answer++;
        while(!(myque.empty())){
            vector<int> nowi = myque.front();
            myque.pop();
            for(int j = 0; j<4; j++){
                int newx = nowi[0] + dx[j];
                int newy = nowi[1] + dy[j];
                if(newx < 0 || newx >= n || newy < 0 || newy >= n){
                    continue;
                }
                if(maps[newx][newy] == 0){
                    maps[newx][newy] = -1;
                    myque.push({newx, newy});
                    answer++;
                }
            }
        }


    }

    cout << answer;
    return 0;
}