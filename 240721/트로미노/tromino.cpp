#include <iostream>
#include <vector>
using namespace std;

/*
-------
* 
* *
index, {+1, 0}, {+1, +1}
-------
* *
*
index, {0, +1}, {+1, 0}
-------
* *
  *
index, {0, +1}, {+1, +1}
-------
  *
* *
index, {+1, 0}, {-1, -1}
-------
* * *
index, {0, +1}, {0, +2}
-------
*
*
*
index, {+1, 0}, {+2, 0}
-------
*/

vector<vector<vector<int>>> blocks = {
    {{+1, 0}, {+1, +1}},
    {{0, +1}, {+1, 0}},
    {{0, +1}, {+1, +1}},
    {{+1, 0}, {-1, -1}},
    {{0, +1}, {0, +2}},
    {{+1, 0}, {+2, 0}}
};

// index위치에서 넣을 수 있는 6가지 모양 count중 최대값
int max_count(vector<vector<int>> maps, vector<int> index){
    
    int max = 0;
    int a = index[0];
    int b = index[1];

    int amax = maps.size();
    int bmax = maps[0].size();

    for(int i = 0; i<6; i++){

        int new1a = a + blocks[i][0][0];
        if(new1a < 0 || new1a >= amax){
            continue;
        }
        int new1b = b + blocks[i][0][1];
        if(new1b < 0 || new1b >= bmax){
            continue;
        }
        int new2a = a + blocks[i][1][0];
        if(new2a < 0 || new2a >= amax){
            continue;
        }
        int new2b = b + blocks[i][1][1];
        if(new2b < 0 || new2b >= bmax){
            continue;
        }

        int counts = maps[a][b] 
                    + maps[new1a][new1b]
                    + maps[new2a][new2b];
        if(max < counts){
            max = counts;
        }
    }

    return max;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> maps(n, vector<int>(m, 0));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int temp;
            cin >> temp;
            maps[i][j] = temp;
        }
    }

    int max = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int counts = max_count(maps, {i, j});
            if(max < counts){
                max = counts;
            }
        }
    }

    cout << max << endl;
    return 0;
}