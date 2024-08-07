#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    cin >> n;
    vector<int> numbers;
    vector<int> count(100000, 0);

    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }

    int j = 0;
    int result = INT_MIN;
    for(int i = 0; i<n; i++){
        while(j < n){
            if(count[numbers[j]] != 0){
                // 중복!
                break;
            }
            count[numbers[j]]++;
            j++;
        }
        result = max(result, j - i + 1);
    }
    cout << result;

    return 0;
}