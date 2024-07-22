#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    string str;
    cin >> str;

    int counts = 0;

    for(int i = 0; i<n; i++){
        if(str[i] == 'C'){
            for(int j = i+1; j<n; j++){
                if(str[j] == 'O'){
                    for(int k = j+1; k<n; k++){
                        if(str[k] == 'W'){
                            counts++;
                        }
                    }
                }
            }
        }
    }

    cout << counts << endl;

    return 0;
}