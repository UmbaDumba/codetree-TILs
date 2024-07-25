#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    if(n >= 3000){
        cout << "book"<<endl;
        return 0;
    }else if(n >= 1000){
        cout << "mask"<<endl;
        return 0;
    }
    cout << "no"<<endl;
    return 0;
}