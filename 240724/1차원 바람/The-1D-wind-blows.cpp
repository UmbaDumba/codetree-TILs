#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> buildings(n, vector<int>(m, 0));
    vector<vector<int>> new_b(n, vector<int>(m, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int temp;
            cin >> temp;
            buildings[i][j] = temp;
        }
    }

    for(int i = 0; i<q; i++){
        int r, dn;
        char d;
        cin >> r >> d;
        if(d == 'L'){
            dn = 1;
        }else if(d == 'R'){
            dn = -1;
        }
        for(int j = 0; j<m; j++){
            new_b[r-1][j] += dn;
        }

        // up
        int dn_up = dn;
        for(int j = r-2; j>=0; j--){
            bool is_ex = false;
            for(int k = 0; k<m; k++){
                int newindex1 = k - new_b[j][k];
                if(newindex1 >= m){
                    newindex1 -= m;
                }else if(newindex1 < 0){
                    newindex1 += m;
                }
                int newindex2 = k - new_b[j+1][k];
                if(newindex2 >= m){
                    newindex2 -= m;
                }else if(newindex2 < 0){
                    newindex2 += m;
                }
                if(buildings[j][newindex1] == buildings[j+1][newindex2]){
                    //cout << "test"<<endl;
                    is_ex = true;
                    break;
                }
            }
            if(!is_ex){
                break;
            }
            dn_up *= -1;
            for(int k = 0; k<m; k++){
                new_b[j][k] += dn_up;
            }
        }

        // down
        int dn_down = dn;
        for(int j = r; j<n; j++){
            bool is_ex = false;
            for(int k = 0; k<m; k++){
                int newindex1 = k - new_b[j][k];
                if(newindex1 >= m){
                    newindex1 -= m;
                }else if(newindex1 < 0){
                    newindex1 += m;
                }
                int newindex2 = k - new_b[j-1][k];
                if(newindex2 >= m){
                    newindex2 -= m;
                }else if(newindex2 < 0){
                    newindex2 += m;
                }
                if(buildings[j][newindex1] == buildings[j-1][newindex2]){
                    is_ex = true;
                    break;
                }
            }
            if(!is_ex){
                break;
            }
            dn_down *= -1;
            for(int k = 0; k<m; k++){
                new_b[j][k] += dn_down;
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            //cout << new_b[i][j] << " ";
            int newj = j - new_b[i][j];
            if(newj < 0){
                newj+=m;
            }else if(newj >= m){
                newj-=m;
            }
            cout << buildings[i][newj]<<" ";
        }
        cout << endl;
    }

    return 0;
}