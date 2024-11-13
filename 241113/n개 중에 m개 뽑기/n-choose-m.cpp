#include <iostream>
#include <vector>
using namespace std;

vector<int> answer;
int n, m;

void print_ans(){
    for(int i = 0; i<answer.size(); i++){
        cout << answer[i]<<" ";
    }
    cout << "\n";
}

void dfs(int num, int count){
    if(count == m){
        print_ans();
        return;
    }
    if(num > n){
        return;
    }

    answer.push_back(num);
    dfs(num+1, count+1);
    answer.pop_back();

    dfs(num+1, count);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    dfs(1, 0);
    return 0;
}