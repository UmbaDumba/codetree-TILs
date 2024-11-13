#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define MAX_N 10

using namespace std;

// 변수 선언
int n;
int cost[MAX_N][MAX_N];
bool visited[MAX_N];
vector<int> picked;

int ans = INT_MAX;

// 지금까지 방문한 지점의 수를 cnt라 했을 때
// 계속 탐색을 이어서 진행합니다.
void FindMin(int cnt) {
    if(cnt == n) {
        int total_cost = 0;
        for(int i = 0; i < (int) picked.size() - 1; i++) {
            int curr_cost = cost[picked[i]][picked[i + 1]];
            // 만약 비용이 0이라면 불가능한 경우이므로 
            // 바로 함수를 빠져나옵니다.
            if(curr_cost == 0)
                return;
            
            total_cost += curr_cost;
        }

        // 최종적으로 1번 지점으로 다시 돌아오는 것 까지 고려해서 계산해줍니다.
        int additional_cost = cost[picked.back()][0];
        if(additional_cost == 0)
            return;

        // 답을 갱신해줍니다.
        ans = min(ans, total_cost + additional_cost);
        return;
    }

    // 방문할 지점을 선택합니다.
    for(int i = 0; i < n; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        picked.push_back(i);

        FindMin(cnt + 1);

        visited[i] = false;
        picked.pop_back();
    }
}

int main() {
    // 입력:
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];

    // 1번 지점을 시작으로
    // 탐색을 진행합니다.
    visited[0] = true;
    picked.push_back(0);
    FindMin(1);

    cout << ans;
    return 0;
}