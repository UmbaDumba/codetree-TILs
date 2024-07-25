#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b, c;
    cin >> a>>b>>c;

    vector<int> numbers = {a,b,c};

    sort(numbers.begin(), numbers.end());

    cout << numbers[1]<<endl;

    return 0;
}