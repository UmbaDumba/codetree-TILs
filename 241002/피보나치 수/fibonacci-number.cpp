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
    memo[n] = fibo(n-1) + fibo(n-2);
    return memo[n];
}

int main() {
    // 여기에 코드를 작성해주세요.
    memo = vector<int>(50, -1);

    int n;
    cin >> n;

    cout << fibo(n);

    return 0;
}