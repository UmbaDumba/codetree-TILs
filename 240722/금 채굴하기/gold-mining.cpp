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

void dfs(vector<vector<int>> *result, vector<int> combi, int now,int m, int n){
    if(now > m){
        return;
    }
    if(combi.size() == n){
        (*result).push_back(combi);
        return;
    }
    dfs(result, combi, now+1, m, n);
    combi.push_back(now);
    dfs(result, combi, now+1, m, n);
}

vector<vector<int>> sub_index(int m, int n){
    // m개 중 n개를 골라 만든 모든 조합
    vector<vector<int>> result;
    if(m == n){
        vector<int> lst;
        for(int i = 0; i<m; i++){
            lst.push_back(i);
        }
        result.push_back(lst);
        return result;
    }
    dfs(&result, {}, 0, m, n);
    return result;

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

    if(total_golds < 1){
        // gold가 하나도 없는경우
        cout << "0" << endl;
        return 0;
    }else if(total_golds == 1){
        // 1개만 있는경우
        cout << "1"<<endl;
        return 0;
    }

    for(int i = total_golds; i>0; i--){
        vector<vector<int>> coms = sub_index(total_golds, i);
        for(int j = 0; j<coms.size(); j++){
            int max_step = 0;
            vector<int> now_com = coms[j];
            vector<int> now_steps;
            for(int k = 0; k<i; k++){
                for(int l = k+1; l<i; l++){
                    int stepss = steps(golds_index[now_com[k]], golds_index[now_com[l]]);
                    if(max_step < stepss){
                        max_step = stepss;
                    }
                }
            }
            int k = (max_step + 1)/2;
            if(i * m > mine_cost(k)){
                cout << i << endl;
                return 0;
            }
        }
    }

    cout << "1"<<endl;


    return 0;
}