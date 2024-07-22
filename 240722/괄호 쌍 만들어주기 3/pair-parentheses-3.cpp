#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;
    int counts = 0;
    for(int i = 0; i<str.size(); i++){
        if(str[i] == '('){
            for(int j = i+1; j<str.size(); j++){
                if(str[j] == ')'){
                    counts++;
                }
            }
        }
    }
    cout << counts<<endl;
    return 0;
}