#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

vector<int> step(vector<vector<int>> maps, int x, int y){
    int num = maps[x][y];
    int nextx = -1;
    int nexty = -1;
    int maxnum = 0;
    int n = maps.size();
    
    queue<vector<int>> myque;
    myque.push({x, y});
    while(!(myque.empty())){
        vector<int> nowi = myque.front();
        myque.pop();
        for(int i = 0; i<4; i++){
            int newx = nowi[0] + dx[i];
            int newy = nowi[1] + dy[i];
            if(newx < 0 || newx >=n || newy < 0 || newy >= n){
                continue;
            }
            if(maps[newx][newy] < num){
                
                //cout << "push : "<<newx << " "<<newy<<endl;
                myque.push({newx, newy});
                if(maxnum < maps[newx][newy]){
                    nextx = newx;
                    nexty = newy;
                    maxnum = maps[newx][newy];
                }else if(maxnum == maps[newx][newy]){
                    if(newx < nextx){
                        nextx = newx;
                        nexty = newy;
                        maxnum = maps[newx][newy];
                    }else if(newx == nextx){
                        if(newy < nexty){
                            nextx = newx;
                            nexty = newy;
                            maxnum = maps[newx][newy];
                        }
                    }
                }
                maps[newx][newy] = num;
            }
        }
    }

    return {nextx, nexty};
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    vector<vector<int>> maps(n, vector<int>(n, 0));
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n; j++){
            cin >> maps[i][j];
        }
    }

    int x, y;
    cin >> x >> y;

    vector<int> prev = {x-1, y-1};

    for(int i = 0; i<k; i++){
        vector<int> next = step(maps, prev[0], prev[1]);
        //cout << "next : "<<next[0]<<" "<<next[1]<<endl;
        if(next[0] == -1){
            break;
        }
        prev = next;
    }

    cout << prev[0] + 1 << " "<<prev[1] + 1;

    return 0;
}