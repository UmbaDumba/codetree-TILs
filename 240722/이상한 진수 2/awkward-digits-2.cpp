#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string a;
    cin >> a;
    bool flag = true;
    int result = 0;
    int n = a.size()-1;
    for(int i = 0; i<n; i++){
        if(flag && a[i] == '0'){
            result += pow(2, n-i);
            flag = false;
            continue;
        }
        if(a[i] == '1'){
            result += pow(2, n-i);
        }
    }
    if(a[n] == '1'){
        if(!flag){
            result += 1;
        }
    }else{
        if(flag){
            result += 1;
        }
    }
    
    cout << result << endl;

    return 0;
}