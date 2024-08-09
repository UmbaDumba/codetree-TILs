#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main() {
    // 여기에 코드를 작성해주세요.

    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> candys;
    for(int i = 0; i<n; i++){
        int a, b;
        cin >> a >> b;
        candys.push_back({a, b});
    }

    sort(candys.begin(), candys.end(), cmp);

    int sums = 0;
    int max_sums = 0;
    int limit = 2 * k;
    int i = 0;
    int j;
    int x = candys[0].second; // 범위 초기값 제일왼쪽
    int y = x + limit; // 범위 초기값 제일 오른쪽
    for(j = 0; j<n; j++){
        
        if(candys[j].second > y){
            break;
        }
        sums+=candys[j].first;
    }

    

    max_sums = sums;
    // sums의 초기값은, [x, y]범위의 합
    // i, j : 해당범위에 있는 바구니 위치
    //cout << i << ", "<<j << endl;
    while(y <= candys[n-1].second){
        x++;
        y++;
        while(candys[i].second < x){
            sums-=candys[i].first;
            i++;
        }
        while((j < n) && candys[j].second <= y){
            sums += candys[j].first;
            j++;
        }

        max_sums = max(max_sums, sums);
    }
    
    
    

    cout <<max_sums;

    return 0;
}