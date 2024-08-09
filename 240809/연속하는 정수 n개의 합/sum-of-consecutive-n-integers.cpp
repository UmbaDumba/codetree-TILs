#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<int> nums;
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    int result = 0;
    int j = 0;
    int sum = 0;
    for(int i = 0; i<n; i++){
        while(j<n){
            if(sum >= m){
                // sum > m
                // m은 안되고 넘겨버림 -> 그냥 다음i로 넘어갈것

                // sum == m
                // i~j 까지 합하면 m이 된다! -> answer 증가
                break;
            }
            sum += nums[j];
            j++;
        }
        if(sum == m){
            result++;
        }
        sum -= nums[i];
    }

    cout << result;

    return 0;
}