#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int steps(vector<int> peoples, int start){
    int result = 0;
    int n = peoples.size();
    for(int i = 0; i<n; i++){
        int index = i+start;
        if(index >= n){
            index -= n;
        }
        result += (i * peoples[index]);

    }
    return result;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> peoples;
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        peoples.push_back(temp);
    }

    int max_step = INT_MAX;

    for(int i = 0; i<n; i++){
        int now_step = steps(peoples, i);
        max_step = max_step > now_step ? now_step : max_step;
    }

    cout << max_step << endl;
    
    return 0;
}