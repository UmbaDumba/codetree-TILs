#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a = 1;
    int b = 2;
    int c = 3;
    a = a + b + c;
    b = a;
    c = a;
    cout << a << " "<<b<<" "<<c<<endl;
    return 0;
}