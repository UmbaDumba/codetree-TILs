#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b;
    cin >> a >> b;

    float hap = a + b;
    float cha = a - b;
    float result = hap / cha;

    cout << fixed;
    cout.precision(2);
    cout << result << endl;

    return 0;
}