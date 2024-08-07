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
    int sum = 0;
    for(int i = 0; i<n; i++){
        //cout << "i : "<<i<<endl;
        if(i > 0){
            sum -= numbers[i-1];
        }
        while(j<=n){
            if(sum >= s){
                //cout << "sum, j : "<<sum<<", "<<j << endl;
                break;
            }
            j++;
            sum += numbers[j];
            
        }
        // i   최대숫자 j 모양!!
        if(sum < s){
            continue;
        }
        
        answer = min(answer, j-i + 1);
    }

    if(answer == INT_MAX){
        answer = -1;
    }

    cout << answer;

    return 0;
}