#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
vector<pair<int, int>> lines;

void choose(int nowi, vector<int> indexs, vector<vector<int>> *result){
    if(nowi == m){
        (*result).push_back(indexs);
        return;
    }
    choose(nowi+1, indexs, result);
    indexs.push_back(nowi);
    choose(nowi+1, indexs, result);
}

bool vec_same(vector<int> a, vector<int> b){
    for(int i = 0; i<a.size(); i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    
    vector<int> members;
    for(int i = 1; i<=n; i++){
        members.push_back(i);
    }
    vector<int> first_members = members;

    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        lines.push_back({a, b});
    }

    sort(lines.begin(), lines.end(), comp);

    for(int i = 0; i<lines.size(); i++){
        int temp = first_members[lines[i].first-1];
        first_members[lines[i].first-1] = first_members[lines[i].first];
        first_members[lines[i].first] = temp;
    }


    vector<vector<int>> whatlines;
    choose(0, {}, &whatlines);


    int min_garos = INT_MAX;
    for(int i = 1; i<whatlines.size(); i++){
        vector<int> now_lines = whatlines[i];
        vector<int> now_members = members;
        for(int j = 0; j<now_lines.size(); j++){
            int temp = now_members[lines[now_lines[j]].first - 1];
            now_members[lines[now_lines[j]].first - 1] = now_members[lines[now_lines[j]].first];
            now_members[lines[now_lines[j]].first] = temp;
        }
        if(vec_same(first_members, now_members)){
            //cout << "test"<<endl;
            //cout << (int)now_lines.size() << endl;
            min_garos = min(min_garos, (int)now_lines.size());
        }
    }

    if(min_garos == m){
        min_garos = 0;
    }

    cout << min_garos;


    return 0;
}