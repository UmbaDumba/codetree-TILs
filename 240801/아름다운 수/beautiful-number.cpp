#include <iostream>
using namespace std;

int answer = 0;
int n;

void solution(int last, int count, int len){
    //cout << last << " "<<count << " "<<len<<endl;
    if((len == n) && (last == count)){
        //cout << "end"<<endl;
        answer++;
        return;
    }

    if(len > n){
        return;
    }

    if(last == count){
        // 다른숫자 나오기 가능
        for(int i = 1; i<=4; i++){
            solution(i, 1, len+1);
        }
    }else if(last > count){
        // 연속된 숫자를 넣어야 가능
        solution(last, count+1, len+1);
    }
    // 아름다운 수가 아님
}

int main() {
    // 여기에 코드를 작성해주세요.
    //int n;
    cin >> n;
    //cout << n << endl;

    solution(0, 0, 0);

    cout << answer;

    return 0;
}