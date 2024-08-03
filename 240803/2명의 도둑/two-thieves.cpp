#include <iostream>
#include <vector>
using namespace std;

int n, m, c;
vector<vector<int>> house;
vector<vector<int>> mcn;


bool is_in(int x1, int y1, int x2, int y2){
    // 도둑1,2의 제일 왼쪽칸이 주어졌을 때, 겹치는지 확인
    return ((x1 == x2) && (((y1 + m > y2) && (y1 <= y2)) || ((y2 + m > y1) && (y1 >= y2))));
}

int values(int x, int y){
    // x, y위치에서 물건을 훔칠 때 가치
    int result = 0;
    for(int i = 0; i<mcn.size(); i++){
        int nowvalue = 0;
        int chec_c = 0;
        for(int j = 0; j<mcn[i].size(); j++){
            if(y+mcn[i][j] >= n){
                break;
            }
            chec_c += house[x][y+mcn[i][j]];
            nowvalue += (house[x][y+mcn[i][j]] * house[x][y+mcn[i][j]]);
        }
        if(chec_c <= c){
            result = max(result, nowvalue);
        }
    }
    return result;
}

void choose(int nowx, vector<int> numbers){
    if(nowx == m){
        mcn.push_back(numbers);
        return;
    }
    choose(nowx+1, numbers);
    numbers.push_back(nowx);
    choose(nowx+1, numbers);
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> m >> c;
    house = vector<vector<int>>(n, vector<int>(n, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> house[i][j];
        }
    }

    choose(0, {});

    int answer = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            // [i, j] : 도둑1의 위치
            for(int k = 0; k<n; k++){
                for(int l = 0; l<n; l++){
                    // [k, l] : 도둑2의 위치
                    if(is_in(i, j, k, l)){
                        continue;
                    }
                    //cout << values(i, j) + values(k, l)<<endl;
                    answer = max(answer, values(i, j) + values(k, l));
                    
                }
            }
        }
    }
    cout << answer;

    return 0;
}