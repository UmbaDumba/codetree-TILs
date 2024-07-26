#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    vector<int> ages;
    while(true){
        int temp;
        cin >> temp;
        if(temp >= 30 || temp < 20){
            break;
        }
        ages.push_back(temp);
    }

    cout << fixed;
    cout.precision(2);
    int sum = accumulate(ages.begin(), ages.end(), 0);
    int n = ages.size();
    cout << (float)sum / (float)n << endl;
    

    return 0;
}