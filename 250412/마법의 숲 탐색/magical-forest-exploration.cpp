#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int answer = 0;
    int r, c, k;
    cin >> r >> c >> k;

    vector<vector<int>> maps(r, vector<int>(c, 0));

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};


    for(int i = 0; i<k; i++)
    {
       
       /*
       cout << "i. : "<< i << endl;
        for(int j = 0; j<r; j++)
        {
            for(int k = 0; k<c; k++)
            {
                cout << maps[j][k] <<" ";
            }
            cout << endl;
        }
        */

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
            continue;
        }


        // 골렘 중간이 [0][x]
        if(maps[1][y] == 0 && y - 1 >= 0 && maps[0][y-1] == 0 && y + 1 < c && maps[0][y+1] == 0)
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

        // 정령 이동

        // 출구로 나가는경우
        int outx = x + dx[d];
        int outy = y + dy[d];
        int outcolvalue = 0;
        for(int j = 0; j<4; j++)
        {
            int cx = outx + dx[j];
            int cy = outy + dy[j];
            if(cx < 0 || cx >= r || cy < 0 || cy >= c)
            {
                continue;
            }
            outcolvalue = max(outcolvalue, maps[cx][cy]);
        }

        // 지금위치에서 젤 아래로 간 경우와 비교
        int colvalue = max(outcolvalue, x + 2);

        // map에 저장
        maps[x][y] = colvalue;
        for(int j = 0; j<4; j++)
        {
            maps[x+dx[j]][y+dy[j]] = colvalue;
        }

        //cout << colvalue << endl;
        answer+=colvalue;
    }

    
    cout << answer;
    return 0;
}