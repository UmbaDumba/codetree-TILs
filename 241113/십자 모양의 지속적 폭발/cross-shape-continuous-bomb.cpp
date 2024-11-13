#include <iostream>
#include <cmath>

#define MAX_N 200
#define OUT_OF_GRID -1

using namespace std;

int n, m;
int grid[MAX_N][MAX_N];
int next_grid[MAX_N][MAX_N];

bool InBombRange(int x, int y, int center_x, int center_y, int bomb_range) {
    return (x == center_x || y == center_y) && 
           abs(x - center_x) + abs(y - center_y) < bomb_range;
}

void Bomb(int center_x, int center_y) {
    for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
            next_grid[i][j] = 0;

	int bomb_range = grid[center_x][center_y];
    
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(InBombRange(i, j, center_x, center_y, bomb_range))
				grid[i][j] = 0;
	
    // Step3. 폭탄이 터진 이후의 결과를 next_grid에 저장합니다.
	for(int j = 0; j < n; j++) {
        int next_row = n - 1;
		for(int i = n - 1; i >= 0; i--) {
			if(grid[i][j])
				next_grid[next_row--][j] = grid[i][j];
		}
    }
	
    // Step4. grid로 다시 값을 옮겨줍니다.
    for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
            grid[i][j] = next_grid[i][j];
}

int GetBombRow(int col) {
    for(int row = 0; row < n; row++)
        if(grid[row][col] != 0)
            return row;
    
    return OUT_OF_GRID;
}

int main() {
	cin >> n >> m;
    
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> grid[i][j];
	
    // m번에 걸쳐 폭탄이 터집니다.
	while(m--) {
		int bomb_col;
		cin >> bomb_col; bomb_col--;
        
        // 폭탄이 터지게 될 위치를 구합니다.
		int bomb_row = GetBombRow(bomb_col);
		
		if(bomb_row == OUT_OF_GRID)
			continue;
		
		Bomb(bomb_row, bomb_col);
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << grid[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}