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

void choose(vector<int> liness, int count){
    if(count == n){
        line_choose.push_back(liness);
        return;
    }
    choose(liness, count+1);
    liness.push_back(count);
    choose(liness, count+1);
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

    choose({}, 0);


    int answer = 0;

    for(int i = 0; i<line_choose.size(); i++){
        int count = 0;
        bool isok = true;
        if(line_choose[i].size() == 1){
            count = 1;
        }else{
            for(int j = 0; j<line_choose[i].size(); j++){
                for(int k = j+1; k<line_choose[i].size(); k++){
                    if(lines[line_choose[i][j]][1] >= lines[line_choose[i][k]][0]){
                        //겹침
                        //cout << lines[line_choose[i][j]][1] << " "<<lines[line_choose[i][k]][0]<<endl;
                        isok = false;
                        break;
                    }
                }
                if(!isok){
                    break;
                }
            }
        }
        if(isok){
            count = line_choose[i].size();
        }
        //cout << "count : "<<count<<endl;
        answer = max(answer, count);
    }

    cout << answer;

    return 0;
}