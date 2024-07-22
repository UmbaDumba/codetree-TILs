#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int r, c;
    cin >> r;
    cin >> c;
    vector<vector<int>> maps(r, vector<int>(c, 0));
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            char temp;
            cin >> temp;
            
            if(temp == 'B'){
                maps[i][j] = 1;
            }
        }
    }

    // index가 0인곳들은 못감 (0,0)에서 시작해서 대각선 아래로만 가야함
    int counts = 0;

    for(int i = 1; i<r-1; i++){
        for(int j = 1; j<c-1; j++){
            // 첫번째 이동위치에 대한 for문
            if(maps[i][j] == maps[0][0]){
                // 이동하지 못하는 위치
                continue;
            }
            for(int k = i+1; k<r-1; k++){
                for(int l = j+1; l<c-1; l++){
                    // 두번째 이동위치에 대한 for문
                    if(maps[i][j] == maps[k][l]){
                        continue;
                    }
                    counts++;
                }
            }
        }
    }

    cout << counts<<endl;

    return 0;
}