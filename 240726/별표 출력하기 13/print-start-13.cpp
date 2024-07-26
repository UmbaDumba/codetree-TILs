#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    for(int i = n; i>0; i--){
        for(int j = 0; j<i; j++){
            cout << "* ";
        }
        cout << endl;
        for(int j = 0; j<(n-i+1); j++){
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}