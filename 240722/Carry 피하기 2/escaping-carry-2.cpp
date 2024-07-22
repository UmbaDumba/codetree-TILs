#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int carry_sum(string a, string b, string c){
    int an = a.size();
    int bn = b.size();
    int cn = c.size();
    int maxn = max(an, bn);
    maxn = max(maxn, cn);

    for(int i = 1; i<=maxn; i++){
        int ain = an - i;
        int bin = bn - i;
        int cin = cn - i;
        
        int carry_check = 0;
        if(ain >= 0){
            carry_check += a[ain] - '0';
        }
        if(bin >= 0){
            carry_check += b[bin] - '0';
        }
        if(cin >= 0){
            carry_check += c[cin] - '0';
        }
        if(carry_check > 9){
            return -1;
        }
    }

    return stoi(a) + stoi(b) + stoi(c);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<string> numbers;
    for(int i = 0; i<n; i++){
        string temp;
        cin >> temp;
        numbers.push_back(temp);
    }

    int maxsum = -1;

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                int csum = carry_sum(numbers[i], numbers[j], numbers[k]);
                maxsum = max(csum, maxsum);
            }
        }
    }

    cout << maxsum << endl;

    return 0;
}