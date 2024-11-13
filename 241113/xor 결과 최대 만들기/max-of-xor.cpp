#include <iostream>
#include <vector>
using namespace std;

int n, m;
int answer = 0;
vector<int> nums;

void dfs(int num, int count, int index){
    if(count == m){
        answer = max(answer, num);
        return;
    }
    if(index >= n){
        return;
    }

    dfs(num, count, index+1);

    num = num ^ nums[index];
    dfs(num, count+1, index+1);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    dfs(0, 0, 0);

    cout << answer;

    return 0;
}