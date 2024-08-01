#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> boom_map;
vector<vector<int>> boom_cases;
int booms;

vector<vector<vector<int>>> myboom = {
    {{2, 0}, {1, 0}, {-1, 0}, {-2, 0}},
    {{1, 0}, {-1, 0}, {0, 1}, {0, -1}},
    {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}
};

void choose(vector<int> boomlist){
    if(boomlist.size() == booms){
        boom_cases.push_back(boomlist);
        return;
    }
    for(int i = 0; i<3; i++){
        vector<int> nowvec = boomlist;
        nowvec.push_back(i);
        choose(nowvec);
    }

}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    for(int i = 0; i <n; i++){
        for(int j = 0; j<n; j++){
            int temp;
            cin >> temp;
            if(temp == 1){
                boom_map.push_back({i, j});
            }
        }
    }

    booms= boom_map.size();
    choose({});

    int answer = 0;

    for(int i = 0; i<boom_cases.size(); i++){
        int blues = 0;
        vector<vector<int>> maps(n, vector<int>(n, 0));
        for(int j = 0; j<boom_cases[i].size(); j++){
            if(maps[boom_map[j][0]][boom_map[j][1]] != 1){
                maps[boom_map[j][0]][boom_map[j][1]] = 1;
                blues++;
            }
            
            for(int k = 0; k<4; k++){
                int newx = boom_map[j][0] + myboom[boom_cases[i][j]][k][0];
                int newy = boom_map[j][1] + myboom[boom_cases[i][j]][k][1];
                if(newx < 0 || newx >= n || newy < 0 || newy >= n){
                    continue;
                }
                if(maps[newx][newy] != 1){
                    maps[newx][newy] = 1;
                    blues++;
                }
            }
        }
        answer = max(answer, blues);
    }
    
    cout <<answer << endl;


    return 0;
}