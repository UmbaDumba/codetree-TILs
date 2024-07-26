#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = -(n-1); i<n; i++){
        for(int j = 0; j<abs(i); j++){
            cout << " ";
        }
        for(int j = 0; j<(n - abs(i)); j++){
            cout << "* ";
        }
        
        cout << endl;
    }

    return 0;
}