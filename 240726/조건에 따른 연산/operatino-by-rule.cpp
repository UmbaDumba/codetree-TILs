#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    

    int cnt = 0;
    while(true){
        if(n%2 == 0){
            n = (n*3) + 1;
        }else{
            n = (n*2) + 2;
        }
        cnt++;
            if(n >= 1000){
                cout << cnt << endl;
                return 0;
            }
    }

    return 0;
}