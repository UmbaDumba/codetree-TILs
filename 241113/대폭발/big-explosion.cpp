#include <iostream>

#define MAX_N 100
#define DIR_NUM 4

using namespace std;

int n, m, r, c;
int grid[MAX_N][MAX_N];
int next_grid[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void Expand(int x, int y, int dist) {
    int dx[DIR_NUM] = {-1, 1, 0, 0};
    int dy[DIR_NUM] = {0, 0, -1, 1};
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i] * dist, ny = y + dy[i] * dist;
        if(InRange(nx, ny))
            next_grid[nx][ny] = 1;
    }
}

void Simulate(int dist) {
    // Step1. next_grid 값을 0으로 초기화합니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            next_grid[i][j] = 0;
    
    // Step2. 폭탄을 던지는 시뮬레이션을 진행합니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j])
                Expand(i, j, dist);

    // Step3. next_grid 값을 grid로 업데이트 해줍니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(next_grid[i][j])
                grid[i][j] = 1;
}

int main() {
	cin >> n >> m >> r >> c;
	
	grid[r - 1][c - 1] = 1;
    
    int dist = 1;
    while(m--) {
        Simulate(dist);
        dist *= 2;
    }
	
    int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			ans += grid[i][j];
    
	cout << ans;
	return 0;
}