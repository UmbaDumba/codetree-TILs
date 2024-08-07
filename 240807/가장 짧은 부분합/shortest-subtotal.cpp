#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n, s;
    cin >> n >> s;

    vector<int> numbers;
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }

    int answer = INT_MAX;

    int j = -1;
    for(int i = 0; i<n; i++){
        int sum = 0;
        while(j<=n){
            if(sum >= s){
                break;
            }
            j++;
            sum += numbers[j];
            
        }
        // i   최대숫자 j 모양!!
        if(sum < s){
            // 조건도달 못하고 그냥 j가 범위 넘겨서 튕긴것
            continue;
        }
        answer = min(answer, j-i);
    }

    if(answer == INT_MAX){
        answer = -1;
    }

    cout << answer;

    return 0;
}