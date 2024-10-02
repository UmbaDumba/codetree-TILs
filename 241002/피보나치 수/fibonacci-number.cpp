#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;

int fibo(int n){
    if(memo[n] != -1){
        // 이미 구한값
        return memo[n];
    }
    if(n == 1 || n == 2){
        memo[n] = 1;
        return 1;
    }
    return fibo(n-2) + fibo(n-1);
}

int main() {
    // 여기에 코드를 작성해주세요.
    memo = vector<int>(50, -1);

    int n;
    cin >> n;

    cout << fibo(n);

    return 0;
}