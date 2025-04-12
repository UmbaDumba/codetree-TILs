#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    // Please write your code here.
    int answer = 0;
    int r, c, k;
    cin >> r >> c >> k;

    vector<vector<int>> maps(r, vector<int>(c, 0));
    vector<vector<int>> exit(r, vector<int>(c, 0));

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};


    for(int i = 1; i<=k; i++)
    {
       
       
       //cout << "i. : "<< i << endl;
        
        

        int ci, d;
        cin >> ci >> d;
        ci--;

        int x, y = ci;

        // 골렘중간이 [-1][y] 로 오도록
        if(maps[0][y] == 0)
        {

        }else if((y - 2) >= 0 && maps[0][y-1] == 0){
            y--;
            d--;
            d = (d + 4) % 4;
        }else if((y + 2) < c && maps[0][y+1] == 0)
        {
            y++;
            d++;
            d%=4;
        }else{
            // map 초기화
            maps = vector<vector<int>>(r, vector<int>(c, 0));
            exit = vector<vector<int>>(r, vector<int>(c, 0));
            continue;
        }


        // 골렘 중간이 [0][x]
        if(maps[1][y] == 0 && maps[0][y-1] == 0 && maps[0][y+1] == 0)
        {
            
        }else if(y - 2 >= 0 && maps[1][y-1] == 0 && maps[0][y-1] == 0 && maps[0][y-2] == 0){
            y--;
            d--;
            d = (d + 4) % 4;
        }else if(y + 2 < c && maps[1][y+1] == 0 && maps[0][y+1] == 0 && maps[0][y+2] == 0)
        {
            y++;
            d++;
            d%=4;
        }else{
            // map 초기화
            maps = vector<vector<int>>(r, vector<int>(c, 0));
            exit = vector<vector<int>>(r, vector<int>(c, 0));
            continue;
        }

        

        // 골렘 중간이 [1][x]
        if(maps[2][y] == 0 && maps[1][y-1] == 0 && maps[1][y+1] == 0)
        {
            
        }else if(y - 2 >= 0 && maps[2][y-1] == 0 && maps[1][y-1] == 0 && maps[1][y-2] == 0 && maps[0][y-2] == 0){
            y--;
            d--;
            d = (d + 4) % 4;
        }else if(y + 2 < c && maps[2][y+1] == 0 && maps[1][y+1] == 0 && maps[1][y+2] == 0 && maps[0][y+2] == 0)
        {
            y++;
            d++;
            d%=4;
        }else{
            // map 초기화
            maps = vector<vector<int>>(r, vector<int>(c, 0));
            exit = vector<vector<int>>(r, vector<int>(c, 0));
            continue;
        }

        // [1][y]까지 옴
        x = 1;

        // 2. 최대한 남쪽으로 내려가기 (map 초기화 안됨)
        while(x < r)
        {
            if(x + 2 >= r)
            {
                // 더 못내려감
                break;
            }else if(maps[x+2][y] == 0 && maps[x+1][y-1] == 0 && maps[x+1][y+1] == 0)
            {
            }else if(y - 2 >= 0 && maps[x+2][y-1] == 0 && maps[x+1][y-1] == 0 && maps[x+1][y-2] == 0 && maps[x][y-2] == 0 && maps[x-1][y-1] == 0){
                y--;
                d--;
                d = (d + 4) % 4;
            }else if(y + 2 < c && maps[x+2][y+1] == 0 && maps[x+1][y+1] == 0 && maps[x+1][y+2] == 0 && maps[x][y+2] == 0 && maps[x-1][y+1] == 0)
            {
                y++;
                d++;
                d%=4;
            }else{
                // 여기가 마지막
                break;
            }
            x++;
        }

        maps[x][y] = i;
        for(int j = 0; j<4; j++)
        {
            maps[x+dx[j]][y+dy[j]] = i;
        }
        exit[x + dx[d]][y + dy[d]] = 1;

 

        // 정령 이동
        queue<vector<int>> que;
        que.push({x, y});
        vector<vector<int>> visited(r, vector<int>(c, 0));
        int max_col = x;
        while(!que.empty())
        {
            vector<int> jung = que.front();
            que.pop();

            for(int j = 0; j<4; j++)
            {
                int nx = jung[0] + dx[j];
                int ny = jung[1] + dy[j];
                if(nx < 0 || ny < 0 || nx >= r || ny >= c)
                {
                    continue;
                }

                if(maps[nx][ny] != 0 && visited[nx][ny] == 0 && (maps[nx][ny] == maps[jung[0]][jung[1]] || exit[jung[0]][jung[1]] == 1))
                {
                
                    visited[nx][ny] = 1;
                    max_col = max(max_col, nx);
                    que.push({nx, ny});
                }
            }
        }
        
        

        //cout << colvalue << endl;

        /*
        for(int j = 0; j<r; j++)
        {
            for(int k = 0; k<c; k++)
            {
                cout << maps[j][k] <<" ";
            }
            cout << endl;
        }
        */
        
        //cout << (max_col+1) << endl;
        answer+=(max_col+1);
    }

    
    cout << answer;
    return 0;
}