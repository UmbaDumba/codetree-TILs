#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int houses[n];
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        houses[i] = temp;
    }

    int minsum = INT_MAX;
    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = 0; j<n; j++){
            sum += houses[j] * abs(i-j);
        }
        //cout << "sum : "<<sum<<endl;
        minsum = min(minsum, sum);
    }

    cout << minsum<< endl;

    return 0;
}