#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> numbers;
    for(int i = 1; i<=n; i++){
        int temp;
        cin >> temp;
        numbers.push_back(temp);
        if(i%2 != 0){
            sort(numbers.begin(), numbers.end());
            cout << numbers[i/2]<<" ";
        }

    }
    return 0;
}