#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> line_choose;
vector<vector<int>> lines;

bool comp(vector<int> a, vector<int> b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

void choose(vector<int> liness){
    if(liness.size() == n){
        line_choose.push_back(liness);
        return;
    }
    for(int i = -1; i<n; i++){
        vector<int> nowline = liness;
        nowline.push_back(i);
        choose(nowline);
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        lines.push_back({a, b});
    }

    sort(lines.begin(), lines.end(), comp);

    choose({});

    int answer = 0;

    for(int i = 0; i<line_choose.size(); i++){
        int count = 0;
        for(int j = 0; j<line_choose[i].size(); j++){
            for(int k = j; k<line_choose[i].size(); k++){
                if(line_choose[i][j] == -1 || line_choose[i][k] == -1){
                    continue;
                }
                if(lines[j][1] < lines[k][0]){
                    // 안겹침
                    count++;
                }
            }
        }
        answer = max(answer, count);
    }

    cout << answer;

    return 0;
}