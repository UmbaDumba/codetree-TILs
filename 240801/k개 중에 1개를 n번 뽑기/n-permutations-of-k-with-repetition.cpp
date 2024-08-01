#include <iostream>
#include <vector>
using namespace std;

int n, k;

void printvec(vector<int> vec){
    for(int i = 0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << "\n";
}

void choose(vector<int> number){
    if(number.size() == n){
        printvec(number);
        return;
    }

    //cout << "choo"<<endl;

    //vector<int> nowvec = number;
    for(int i=1; i<=k; i++){
        vector<int> nowvec = number;
        nowvec.push_back(i);
        choose(nowvec);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    //int n, k;
    cin >> k >> n;

    choose({});

    return 0;
}