#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    // n초뒤에는 초기상태와 같아짐
    int n, t;
    cin >> n >> t;
    int turns = t % n;

    int m = n*2;

    vector<int> conv;
    
    for(int i = 0; i<m; i++){
        int temp;
        cin >> temp;
        conv.push_back(temp);
    }

    for(int i = 0; i<m; i++){
        if(i == n){
            cout << endl;
        }
        int index = i - turns;
        if(index < 0){
            index += m;
        }
        cout << conv[index]<<" ";
    }
    cout << endl;


    return 0;
}