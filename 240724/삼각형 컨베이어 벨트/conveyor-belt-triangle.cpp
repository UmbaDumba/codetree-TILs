#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, t;
    cin >> n >> t;
    int m = n * 3;
    int turns = t % m;

    vector<int> conv;
    for(int i = 0; i<m; i++){
        int temp;
        cin >> temp;
        conv.push_back(temp);
    }

    for(int i = 0; i<m; i++){
        if(i % n == 0 && i != 0){
            cout << endl;
        }
        int index = i - turns;
        if(index < 0){
            index += m;
        }
        cout << conv[index] << " ";
    }

    return 0;
}