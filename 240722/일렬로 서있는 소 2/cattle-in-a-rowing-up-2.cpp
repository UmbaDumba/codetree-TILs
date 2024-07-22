#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> cows;
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        cows.push_back(temp);
    }

    int counts = 0;

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                if(cows[i]<=cows[j] && cows[j] <= cows[k]){
                    counts++;
                }
            }
        }
    }

    cout << counts<<endl;
    
    return 0;
}