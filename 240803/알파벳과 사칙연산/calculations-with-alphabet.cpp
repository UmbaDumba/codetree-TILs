#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

string str;


void calc(int i, int sums, int *result, map<char, int> values){
    if(i >= str.size()){
        (*result) = max((*result), sums);
        return;
    }
    // str[i]는 무조건 기호
    // sums str[i] str[i+1] 을 sums로 넘겨주기
    if(values.find(str[i+1]) != values.end()){
        // 이미 있는 변수
        int nextval = values.find(str[i+1])->second;
        if(str[i] == '+'){
            calc(i+2, sums + nextval, result, values);
        }else if(str[i] == '-'){
            calc(i+2, sums - nextval, result, values);
        }else{ // *
            calc(i+2, sums * nextval, result, values);
        }
        return;
    }

    // 아직 없는 변수
    if(str[i] == '+'){
        for(int j = 1; j<=4; j++){
            map<char, int> nextvalues = values;
            nextvalues[str[i+1]] = j;
            calc(i+2, sums + j, result, nextvalues);
        }
    }else if(str[i] == '-'){
        for(int j = 1; j<=4; j++){
            map<char, int> nextvalues = values;
            nextvalues[str[i+1]] = j;
            calc(i+2, sums - j, result, nextvalues);
        }
    }else{ // *
        for(int j = 1; j<=4; j++){
            map<char, int> nextvalues = values;
            nextvalues[str[i+1]] = j;
            calc(i+2, sums * j, result, nextvalues);
        }
    }
    
}

int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> str;

    int result = INT_MIN;
    for(int i = 1; i<=4; i++){
        int nowresult = INT_MIN;
        map<char, int> nextvalues;
        nextvalues[str[0]] = i;
        calc(1, i, &nowresult, nextvalues);
        result = max(result, nowresult);
    }

    cout << result;

    return 0;
}