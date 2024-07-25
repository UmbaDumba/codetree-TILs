#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b, c;
    cin >> a >> b >> c;

    int sum = a+b+c;
    int phung = sum/3;
    cout << sum<<endl;
    cout << phung<<endl;
    cout << sum-phung<<endl;

    return 0;
}