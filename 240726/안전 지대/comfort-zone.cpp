#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>> *maps, int x, int y, int k){
    vector<int> dx = {1, 0 ,-1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int n = (*maps).size();
    int m = (*maps)[0].size();
    for(int i = 0; i<4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(newx < 0 || newx >=n || newy < 0 || newy >= m){
            continue;
        }
        if((*maps)[newx][newy] > k){
            // com
            (*maps)[newx][newy] = -1;
            dfs(maps, newx, newy, k);
        }

    }

}

vector<int> get_seed(vector<vector<int>> maps, int k){
    for(int i = 0; i<maps.size(); i++){
        for(int j = 0; j<maps[0].size(); j++){
            if(maps[i][j] > k){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int get_coms(vector<vector<int>> maps, int k){
    vector<int> seed;
    int result = 0;
    while(true){
        seed = get_seed(maps, k);
        if(seed[0] == -1){
            break;
        }
        result++;
        maps[seed[0]][seed[1]] = -1;
        dfs(&maps, seed[0], seed[1], k);
    }

    return result;

}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> houses(n, vector<int>(m, 0));
    int maxheight = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> houses[i][j];
            maxheight = max(maxheight, houses[i][j]);
        }
    }

    int coms = 0;
    int comk;
    
    for(int k = 1; k<maxheight; k++){
        int nowcon = get_coms(houses, k);
        if(nowcon > coms){
            // 같을때는 더 작은 k를 출력하므로 초과로 확인
            coms = nowcon;
            comk = k;
        }
    }
    

    cout << comk << " "<<coms<<endl;

    return 0;
}