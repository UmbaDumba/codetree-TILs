#include <iostream>
#include <vector>
using namespace std;

vector<int> answer;
int k, n;

void dfs(int num1, int num2, int num){
    if(num > n){
        for(int i = 0; i<n; i++){
            cout << answer[i]<<" ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i<=k; i++){
        if((num1 == num2) && (num2 == i)){
            continue;
        }
        answer.push_back(i);
        dfs(num2, i, num+1);
        answer.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> k >> n;

    dfs(-1, -1, 1);

    return 0;
}