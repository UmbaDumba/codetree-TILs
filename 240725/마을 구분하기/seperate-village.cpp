#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getseed(vector<vector<int>> maps){
    for(int i = 0; i<maps.size(); i++){
        for(int j = 0; j<maps[0].size(); j++){
            if(maps[i][j] == 1){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

void dfs(vector<vector<int>> *maps, int x, int y, int *people){
    int n = (*maps).size();
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for(int i = 0; i<4; i++){
        
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(newx < 0 || newx >= n || newy <0 || newy >= n){
            continue;
        }
        if((*maps)[newx][newy] == 1){
            (*people)++;
            (*maps)[newx][newy] = 0;
            dfs(maps, newx, newy, people);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<vector<int>> vuilges(n, vector<int>(n, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> vuilges[i][j];
        }
    }

    vector<int> seed;
    int vuils = 0;
    vector<int> peoples;
    while(true){
        seed = getseed(vuilges);
        if(seed[0] == -1){
            break;
        }
        vuils++;
        int people = 1;
        vuilges[seed[0]][seed[1]] = 0;
        dfs(&vuilges, seed[0], seed[1], &people);
        peoples.push_back(people);
    }

    sort(peoples.begin(), peoples.end());
    cout << vuils << endl;
    for(int i = 0; i<peoples.size(); i++){
        cout << peoples[i]<<endl;
    }



    return 0;
}