#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;


int mine_cost(int k){
    return (k * k) + ((k+1) * (k+1));
}

int steps(vector<int> a, vector<int> b){
    // 두 점사이에 몇 step이 있는지
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int nc2(int n){
    return (n * (n-1)) / 2;
}

void print_vec(vector<int> vec){
    for(int i = 0; i<vec.size(); i++){
        cout << vec[i]<<" ";
    }
    cout << endl;
}

int main() {
    // 여기에 코드를 작성해주세요.

    int n, m;
    cin >> n;
    cin >> m;

    //vector<vector<int>> maps(n, vector<int>(n,0));
    vector<vector<int>> golds_index;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int temp;
            cin >> temp;
            if(temp == 1){
                golds_index.push_back({i, j});
            }
        }
    }
    // gold가 있는 좌표만 담고있기!
    int total_golds = golds_index.size();

    vector<int> total_steps;
    for(int i = 0; i<total_golds; i++){
        for(int j = i+1; j<total_golds; j++){
            total_steps.push_back(steps(golds_index[i], golds_index[j]));
        }
    }

    sort(total_steps.begin(), total_steps.end());


    for(int i = total_golds; i>0; i--){
        int coms = nc2(i);
        int k = (total_steps[coms-1] + 1) / 2;
        if(i * m > mine_cost(k)){
            cout << i << endl;
            return 0;
        }
    }

    cout << "1"<<endl;


    return 0;
}