#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<pair<int, int>> suns;

    for(int i = 0; i<n; i++){
        int a, b;
        cin >> a >>b;
        suns.push_back({a, b});
    }

    vector<int> dp(n, 1);

    sort(suns.begin(), suns.end(), comp);

    dp[0] = 1;

    for(int i = 1; i<n; i++){
        // [i]를 포함하려고 하면,,, 왼쪽에 있는 것들 중 겹치치 않는애부터 확인하면 된다!
        // [i]를 무조건 포함하는걸로 생각해보기!
        for(int j = 0; j<i; j++){
            if(suns[j].second >= suns[i].first){
                continue;
            }
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}