#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> numbers;
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        numbers.push_back(temp);

    }

    int maxnum = 0;

    for(int i = 0; i<n; i++){
        for(int j = i+2; j<n; j++){
            int nownum = numbers[i] + numbers[j];
            maxnum = maxnum < nownum ? nownum : maxnum;
        }
    }

    cout << maxnum << endl;

    return 0;
}