#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;
    vector<pair<char, int>> codes;

    char prev = str[0];
    int counts = 1;

    for(int i = 1; i<str.size(); i++){
        if(prev != str[i]){
            codes.push_back({prev, counts});
            prev = str[i];
            counts = 1;
            continue;
        }
        counts++;
    }
    codes.push_back({prev, counts});

    if(codes.size() == 1){
        if(codes[0].second < 10){
            cout << "2";
        }else{
            cout << "3";
        }
        return 0;
    }

    if(codes[0].first == codes[codes.size()-1].first){
        codes[0].second += codes[codes.size()-1].second;
        codes.pop_back();
    }

    int answer = 0;

    for(int i = 0; i<codes.size(); i++){
        if(codes[i].second < 10){
            answer += 2;
        }else{
            answer += 3;
        }
    }

    cout << answer;


    return 0;
}