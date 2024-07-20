#include <iostream>
#include <vector>
using namespace std;

// 최대공약수
// a>b
int gcd(int a, int b){
    int mood = a % b;
    if(mood == 0){
        return b;
    }
    return gcd(b, mood);
}

// 최소공배수
int mgb(int a, int b){
    int gcdd;
    if(a > b){
        gcdd = gcd(a, b);
    }else{
        gcdd = gcd(b, a);
    }
    int mull = a * b;
    return mull / gcdd;
}

// n개의 최소공배수
int nmgb(vector<int> numbers){
    if(numbers.size() == 1){
        return numbers[0];
    }
    int n = numbers.size();
    int a = numbers[n-1];
    int b = numbers[n-2];
    numbers.pop_back();
    numbers.pop_back();
    int mgbb = mgb(a, b);
    numbers.push_back(mgbb);
    return nmgb(numbers);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> numbers;
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }

    cout << nmgb(numbers)<<endl;

    return 0;
}