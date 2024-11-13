#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int n, m, k;
vector<int> turns;
int answer = 0;

void dfs(vector<int> mals, int turn){
    if(turn == n){
        int temp = 0;
        for(int i = 0; i<k; i++){
            if(mals[i] >= m){
                temp++;
            }
        }
        answer = max(answer, temp);
        return;
    }
    for(int i = 0; i<k; i++){
        vector<int> next_mal = mals;
        next_mal[i] += turns[turn];
        dfs(next_mal, turn+1);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> m >> k;

    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        turns.push_back(temp);
    }    

    vector<int> mals(k, 1);

    dfs(mals, 0);

    cout << answer;

    return 0;
}