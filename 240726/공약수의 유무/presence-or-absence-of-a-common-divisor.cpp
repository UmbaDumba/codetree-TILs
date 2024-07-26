#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// a > b
int gcd(int a, int b){
    int mod = a % b;
    if(mod == 0){
        return b;
    }
    return (b, mod);
}

vector<int> cds(int n){
    vector<int> result = {n};
    for(int i = 1; i<(n+1)/2; i++){
        if(n % i == 0){
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    // 여기에 코드를 작성해주세요.
    //int gcdnum = gcd(2880, 1920);
    //vector<int> cdnums = cds(gcdnum);

    int a, b;
    cin >> a >> b;
    for(int i = a; i<=b; i++){
        if((2880 % i == 0) && (1920 % i == 0)){
            cout << "1" << endl;
            return 0;
        }
    }
    cout << "0"<< endl;

    return 0;
}