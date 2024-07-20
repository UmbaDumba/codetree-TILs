#include <iostream>
using namespace std;

void changeab(int *a, int *b){
    if(*a > *b){
        *a = *a * 2;
        *b += 10;
        return;
    }
    *b = *b * 2;
    *a += 10;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b;
    cin >> a;
    cin >> b;

    changeab(&a, &b);

    cout << a << " "<<b << endl;

    return 0;
}