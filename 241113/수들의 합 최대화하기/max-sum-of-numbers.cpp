#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 10

using namespace std;

// 변수 선언
int n;
int grid[MAX_N][MAX_N];
bool visited[MAX_N];
vector<int> picked;

int ans;

void FindMax(int row) {
    // 색칠된 칸에 적힌 수들의 합 중
    // 최댓값을 갱신합니다.
    if(row == n) {
        int sum = 0;
        for(int i = 0; i < (int) picked.size(); i++)
            sum += grid[i][picked[i]];

        // 답을 갱신해줍니다.
        ans = max(ans, sum);
        return;
    }

    // 현재 행에 색칠할 열을 선택합니다.
    for(int i = 0; i < n; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        picked.push_back(i);

        FindMax(row + 1);

        visited[i] = false;
        picked.pop_back();
    }
}

int main() {
    // 입력:
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    // 합이 최대가 되도록
    // 탐색을 진행합니다.
    FindMax(0);

    cout << ans;
    return 0;
}