#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    for(int i = 0; i<5; i++){
        int temp;
        cin >> temp;
        if(temp % 3 != 0){
            cout << "0" << endl;
            return 0;
        }
    }
    cout << "1"<<endl;

    return 0;
}