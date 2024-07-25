#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        if((temp%2==1) && (temp%3==0)){
            cout << temp <<endl;
        }
    }
    return 0;
}