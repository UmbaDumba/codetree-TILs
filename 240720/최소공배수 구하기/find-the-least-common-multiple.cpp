#include <iostream>
using namespace std;

// a > b
int gcd(int a, int b){
    int mood = a % b;
    if(mood == 0){
        return b;
    }
    return gcd(b, mood);
}

int lcd(int a, int b){
    int mul = a * b;
    int gcdd;
    if(a > b){
        gcdd = gcd(a, b);
    }else{
        gcdd = gcd(b, a);
    }
    return mul / gcdd;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n;
    cin >> m;



    cout << lcd(n, m) << endl;

    return 0;
}