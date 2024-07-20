#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n;
    cin >> m;

    vector<int> sequence(n, 0);
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        sequence[i] = temp;
    }

    for(int i = 0; i<m; i++){
        int a1, a2;
        cin >> a1;
        cin >> a2;
        int sum = accumulate(sequence.begin()+a1-1, sequence.begin()+a2,0);
        cout << sum << endl;

    }

    return 0;
}