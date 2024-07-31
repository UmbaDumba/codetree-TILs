#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

int cangos(vector<vector<int>> maps, vector<vector<int>> starts){
    int n = maps.size();
    int k = starts.size();
    int answer = 0;
    for(int i = 0; i<k; i++){
        if(maps[starts[i][0]][starts[i][1]] != 0){
            continue;
        }
        queue<vector<int>> myque;
        myque.push(starts[i]);
        maps[starts[i][0]][starts[i][1]] = -1;
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
                    //cout << "push : "<<newx << " "<<newy<<endl;
                    answer++;
                }
            }
        }

    }
    return answer;
}

void dfs(int s, int m, int n, vector<int> numbers, vector<vector<int>> *result){
    if(m == numbers.size()){
        (*result).push_back(numbers);
        return;
    }
    if(s == n){
        return;
    }
    dfs(s, m, n+1, numbers, result);
    numbers.push_back(n);
    dfs(s, m, n+1, numbers, result);
}

vector<vector<int>> colecs(int s, int m){
    // sCm 전체 경우의수
    vector<vector<int>> result;
    dfs(s, m, 0, {}, &result);
    return result;

}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k, m;
    cin >> n >> k >> m;
    vector<vector<int>> maps(n, vector<int>(n, 0));
    vector<vector<int>> stones;
    vector<vector<int>> starts;
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n; j++){
            cin >> maps[i][j];
            if(maps[i][j] == 1){
                stones.push_back({i, j});
            }
        }
    }
 
    for(int i = 0; i<k; i++){
        int x, y;
        cin >> x >> y;
        starts.push_back({x-1, y-1});
    }

    vector<vector<int>> remove_stone = colecs(stones.size(), m);
    int gomax = 0;

    for(int i = 0; i<remove_stone.size(); i++){
        vector<vector<int>> nowmaps = maps;
        for(int j = 0; j<remove_stone[i].size(); j++){
            //cout << stones[remove_stone[i][j]][0]<< ", "<<stones[remove_stone[i][j]][1]<<endl;
            nowmaps[stones[remove_stone[i][j]][0]][stones[remove_stone[i][j]][1]] = 0;
        }
        gomax = max(gomax, cangos(nowmaps, starts));
    }

    cout << gomax << endl;


    return 0;
}