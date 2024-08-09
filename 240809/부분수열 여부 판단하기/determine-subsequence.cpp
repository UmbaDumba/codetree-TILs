#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<int> a;
    vector<int> b;
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    for(int i = 0; i<m; i++){
        int temp;
        cin >> temp;
        b.push_back(temp);
    }

    int j = 0;
    string result = "No";
    for(int i = 0; i<n; i++){
        if(j >= m){
            result = "Yes";
            break;
        }
        if(a[i] == b[j]){
            j++;
        }
    }
    if(j >= m){
        result = "Yes";
    }

    cout << result;

    return 0;
}