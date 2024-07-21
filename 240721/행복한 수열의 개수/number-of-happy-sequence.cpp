#include <iostream>
#include <vector>
using namespace std;

// true : column기준
// false : row기준
// n번째 col(row)가 happy인지 판별
bool is_happy(vector<vector<int>> arrays, bool col, int n, int m){
    if(col){
        int num = arrays[0][n];
        int count = 0;
        for(int i = 0; i<arrays.size(); i++){
            if(count >= m){
                return true;
            }
            if(arrays[i][n] == num){
                count++;
                continue;
            }
            num = arrays[i][n];
            count = 1;
        }
        if(count >= m){
                return true;
        }
    }else{
        int num = arrays[n][0];
        int count = 0;
        for(int i = 0; i<arrays.size(); i++){
            if(count >= m){
                return true;
            }
            if(arrays[n][i] == num){
                count++;
                continue;
            }
            num = arrays[n][i];
            count = 1;
        }
        if(count >= m){
                return true;
        }
    }
    return false;
}

// n번째 row, col모두 비교
// 0, 1, 2 <- happy개수 리턴
int howmany_happy(vector<vector<int>> arrays, int n, int m){
    int num_col = arrays[0][n];
    int num_row = arrays[n][0];
    int count_col = 0;
    int count_row = 0;

    int happy_col = 0;
    int happy_row = 0;

    for(int i = 0; i<arrays.size(); i++){
        if(count_col >= m){
            happy_col = 1;
            break;
        }
        if(count_row >= m){
            happy_row = 1;
            break;
        }
        if(arrays[i][n] == num_col){
            count_col++;
            continue;
        }
        if(arrays[n][i] == num_row){
            count_row++;
            continue;
        }
        num_col = arrays[i][n];
        count_col = 1;
        num_row = arrays[n][i];
        count_row = 1;
    }
    
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n;
    cin >> m;
    
    vector<vector<int>> arrays(n, vector<int>(n,0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int temp;
            cin >> temp;
            arrays[i][j] = temp;
        }
    }

    int count = 0;
    for(int i = 0; i<n; i++){
        bool is_happycol = is_happy(arrays, true, i, m);
        bool is_happyrow = is_happy(arrays, false, i, m);
        if(is_happycol){
            count++;
        }
        if(is_happyrow){
            count++;
        }
    }

    cout << count << endl;


    return 0;
}