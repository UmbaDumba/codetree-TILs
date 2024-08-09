#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    sort(nums.begin(), nums.end());

    int j = n-1;
    int answer = 0;
    for(int i = 0; i<n; i++){
        // 제일 작은거랑 큰거 더해서 비교
        // -> k보다 크면? j를 줄이기
        // -> k이하일때 : 경우의수 1증가 &&  j줄여서 반복
        if(i == j){
            break;
        }
        int test = nums[i] + nums[j];
        if(test > k){
            j--;
            i--;
            continue;
        }else{
            answer+=(j-i);
            continue;
        }
    }

    cout << answer;

    return 0;
}