#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>> *maps, int x, int y, int *size, int n){
    int ns = (*maps).size();
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for(int i = 0; i<4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(newx < 0 || newx >= ns || newy < 0 || newy >= ns){
            continue;
        }
        if((*maps)[newx][newy] == n){
            (*size)++;
            (*maps)[newx][newy] = -1;
            dfs(maps, newx, newy, size, n);
        }
    }

}

vector<int> get_seed(vector<vector<int>> maps, int n){
    for(int i = 0; i<maps.size();i++){
        for(int j = 0; j<maps.size(); j++){
            if(maps[i][j] == n){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// n : 숫자몇짜리 테스트할것인지
// return : (pang 개수, 최대크기)
vector<int> ppuyo(vector<vector<int>> maps, int n){
    vector<int> result = {0, 0};
    vector<int> seed;
    while(true){
        seed = get_seed(maps, n);
        if(seed[0] == -1){
            break;
        }
        int size = 1;
        maps[seed[0]][seed[1]] = -1;
        dfs(&maps, seed[0], seed[1], &size, n);
        if(size >= 4){
            result[0]++;
        }
        result[1] = max(result[1], size);
        
    }
    return result;

}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<vector<int>> maps(n, vector<int>(n, 0));
    vector<int> numbers;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> maps[i][j];
            if(find(numbers.begin(), numbers.end(), maps[i][j]) == numbers.end()){
                numbers.push_back(maps[i][j]);
            }
        }
    }
    
    int maxpang = -1;
    int maxsize = -1;

    for(int i = 0; i<numbers.size(); i++){
        vector<int> nowppyyo = ppuyo(maps, numbers[i]);
        maxpang = max(maxpang, nowppyyo[0]);
        maxsize = max(maxsize, nowppyyo[1]);
    }

    
    cout << maxpang << " "<<maxsize<<endl;

    
    return 0;
}