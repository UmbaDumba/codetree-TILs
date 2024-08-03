#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> ices;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

int melting(){
    vector<vector<int>> visit(n, vector<int>(m, 0));
    int melts = 0;
    queue<pair<int, int>> myque;
    myque.push({0, 0});
    visit[0][0] = 1;
    while(!myque.empty()){
        pair<int, int> nowindex = myque.front();
        myque.pop();
        for(int i = 0; i<4; i++){
            int newx = nowindex.first + dx[i];
            int newy = nowindex.second + dy[i];
            if(newx < 0 || newx >= n || newy < 0 || newy >= m){
                continue;
            }
            if(visit[newx][newy] == -1){
                // 녹인곳
                continue;
            }
            if(visit[newx][newy] == 0){
                if(ices[newx][newy] == 0){
                    myque.push({newx, newy});
                    visit[newx][newy] = 1;
                }else{
                    ices[newx][newy] = 0;
                    visit[newx][newy] = -1;
                    melts++;
                }
                
            }
            
        }
    }
    return melts;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    ices = vector<vector<int>>(n, vector<int>(m, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> ices[i][j];
        }
    }

    int melts = 0;
    int time = 0;
    
    while(true){
        int nextmelts = melting();
        if(nextmelts == 0){
            break;
        }
        time++;
        melts = nextmelts;

    }
    

    
    
    cout << time << " " <<melts;

    return 0;
}