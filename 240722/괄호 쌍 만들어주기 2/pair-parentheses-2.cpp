#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;
    int counts = 0;
    for(int i = 0; i<str.size()-3; i++){
        if(str[i] == '(' && str[i+1] == '('){
            for(int j = i+2; j<str.size()-1; j++){
                if(str[j] == ')' && str[j+1] == ')'){
                    counts++;
                }
            }
        }
    }
    cout << counts<<endl;
    return 0;
}