#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>
using namespace std;

int distance(vector<int> a, vector<int> b){
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int distances(vector<vector<int>> points, int x){
    // x : 안갈 check point index 번호
    int result = 0 ;
    vector<int> prev = points[0];
    for(int i = 1; i<points.size(); i++){
        if(i == x){
            continue;
        }
        vector<int> now = points[i];
        result += distance(prev, now);
        prev = now;
    }
    return result;

}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<vector<int>> check_points;
    for(int i = 0; i<n; i++){
        int a, b;
        cin >> a >> b;
        check_points.push_back({a, b});
    }

    int min = INT_MAX;

    for(int i = 1; i<n-1; i++){
        int dis = distances(check_points, i);
        if(min > dis){
            min = dis;
        }
    }

    cout << min << endl;

    return 0;
}