#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

string str;

void calc(int i, int sums, int *result){
    if(i >= str.size()){
        (*result) = max((*result), sums);
        return;
    }
    // str[i]는 무조건 기호
    // sums str[i] str[i+1] 을 sums로 넘겨주기
    if(str[i] == '+'){
        for(int j = 1; j<=4; j++){
            calc(i+2, sums + j, result);
        }
    }else if(str[i] == '-'){
        for(int j = 1; j<=4; j++){
            calc(i+2, sums - j, result);
        }
    }else{ // *
        for(int j = 1; j<=4; j++){
            calc(i+2, sums * j, result);
        }
    }
    
}

int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> str;

    int result = INT_MIN;
    for(int i = 1; i<=4; i++){
        int nowresult;
        calc(1, i, &nowresult);
        result = max(result, nowresult);
    }

    cout << result;

    return 0;
}