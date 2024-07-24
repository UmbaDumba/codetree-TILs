#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool is_in(vector<int> left, vector<int> right, vector<int> left2, vector<int> right2){
    int x1min = left[0];
    int y1min = left[1];
    int x1max = right[0];
    int y1max = right[1];
    int x2min = left2[0];
    int y2min = left2[1];
    int x2max = right2[0];
    int y2max = right2[1];

    
    if(x1max < x2min || y1max < y2min){
        return true;
    }
    if(x2max < x1min || y2max < y1min){
        return true;
    }

    return false;
}



int lecsum(vector<vector<int>> maps, vector<int> left, vector<int> right){
    int result = 0;
    for(int i = left[0]; i<=right[0]; i++){
        for(int j = left[1]; j<=right[1]; j++){
            result += maps[i][j];
        }
    }
    return result;
}

int lecsum2(vector<vector<int>> maps, vector<int> left, vector<int> right){
    // 사각형을 제외한곳에서의 최대값
    int result = INT_MIN;
    int n = maps.size();
    int m = maps[0].size();
    //cout << "in lecsum2 : "<<left[0]<<", "<<left[1]<<") ("<<right[0]<<", "<<right[1]<<endl;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            // 왼쪽끝
            for(int k = i; k<n; k++){
                for(int l = j; l<m; l++){
                    // 오른쪽끝
                    if(!is_in(left, right, {i, j}, {k, l})){
                        // 겹치는 사각형!
                        continue;
                    }
                    int sum = lecsum(maps, {i, j}, {k, l});
                    if(sum > result){
                        result = sum;
                    }
                }
            }
        }
    }
    return result;
}


int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maps(n, vector<int>(m,0));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int temp;
            cin >> temp;
            maps[i][j] = temp;
        }
    }

    int maxsum1 = INT_MIN;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            // 왼쪽끝
            for(int k = i; k<n; k++){
                for(int l = j; l<m; l++){
                    // 오른쪽끝
                    if((i == 0) && (j == 0) && (k == (n-1)) && (l == (m-1))){
                        continue; // 사각형이 한개밖에 못만들어짐
                    }
                    int sum = lecsum(maps, {i, j}, {k, l});
                    int sum2 = lecsum2(maps, {i, j}, {k, l});
                    sum += sum2;
                    if(sum > maxsum1){
                        //cout << "(i, j) (k, l), sum2 : "<<i<<", "<<j<<") ("<<k<<", "<<l<<") : "<<sum2<<endl;
                        maxsum1 = sum;
                    }
                }
            }
        }
    }

    

    cout << maxsum1 << endl;

    return 0;
}