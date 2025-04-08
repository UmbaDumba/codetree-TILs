#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    
    int n, m;
    vector<int> medusa_home(2), park(2);
    cin >> n >> m;
    vector<vector<int>> zunsas;
    vector<vector<int>> maps(n, vector<int>(n, 0));
    cin >> medusa_home[0] >> medusa_home[1] >> park[0] >> park[1];
    for(int i = 0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        zunsas.push_back({a-1, b-1});
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin >> maps[i][j];
        }
    }

    // step1 : 메두사집 <-> 공원 최단경로구하기 (bfs)
    queue<int> que; // node (i * n + j == index)
    vector<vector<int>> visited(n, vector<int>(n, -1)); // 경로 저장 (어느 노드에서 왔는지)
    
    que.push(medusa_home[0] * n + medusa_home[1]);
    visited[medusa_home[0]][medusa_home[1]] = medusa_home[0] * n + medusa_home[1];

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    while(!que.empty())
    {
        int node = que.front();
        que.pop();

        int index_i = node / n;
        int index_j = node % n;

        if(index_i == park[0] && index_j == park[1])
        {
            break;
        }

        
        for(int i = 0; i<4; i++)
        {
            int nexti = index_i + dx[i];
            int nextj = index_j + dy[i];
            if(nexti >= n || nexti < 0 || nextj >= n || nextj < 0)
            {
                continue;
            }

            if(visited[nexti][nextj] == -1 && maps[nexti][nextj] == 0)
            {
                visited[nexti][nextj] = node;
                que.push(nexti * n + nextj);
            }
        }
        
    }

    // 도착하지 못하면 -1리턴
    if(visited[park[0]][park[1]] == -1)
    {
        cout << -1;
        return 0;
    }

    // 최소경로 stack에 담기
    stack<vector<int>> park_root;
    int testi = park[0];
    int testj = park[1];
    while(1)
    {
        park_root.push({testi, testj});
        if(testi == medusa_home[0] && testj == medusa_home[1])
        {
            break;
        }

        int ntesti = visited[testi][testj] / n;
        int ntestj = visited[testi][testj] % n;

        testi = ntesti;
        testj = ntestj;
        
    }
    
    // stack에서 하나씩 빼면서 게임 진행
    

    return 0;
}