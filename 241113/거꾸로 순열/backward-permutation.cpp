#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;
vector<int> visit;
int n;

void print_vec(){
    for(int i = 0; i<nums.size(); i++){
        cout << nums[i]<<" ";
    }
    cout << "\n";
}

void dfs(int count){
    if(count == n){
        print_vec();
        return;
    }

    for(int i = n-1; i>=0; i--){
        if(visit[i] == 0){
            visit[i] = 1;
            nums.push_back(i+1);
            dfs(count+1);
            nums.pop_back();
            visit[i] = 0;
        }
    }
    
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    visit = vector<int>(n, 0);

    dfs(0);
    return 0;
}