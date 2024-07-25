#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int age1, age2;
    char s1, s2;

    cin >> age1 >> s1;
    cin >> age2 >> s2;

    cout << (((age1 >= 19)&&(s1 == 'M')) || ((age2 >= 19)&&(s2 == 'M')))<<endl;

    return 0;
}