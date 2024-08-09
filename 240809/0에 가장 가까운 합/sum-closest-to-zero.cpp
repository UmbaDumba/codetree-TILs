#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    sort(nums.begin(), nums.end());

    int j = n-1;
    int sum = abs(nums[0] + nums[j]);
    for(int i = 0; i < n; i++){
        if(i == j){
            break;
        }
        int nowsum = nums[i] + nums[j];
        if(nowsum > 0){
            j--;
            i--;
        }else if(nowsum < 0){
            // i증가
        }else{
            // 0인상황
            sum = 0;
            break;
        }
        sum = min(sum, abs(nowsum));
    }

    cout << sum;

    return 0;
}