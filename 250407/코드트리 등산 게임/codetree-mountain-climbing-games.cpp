#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long plays(vector<int> sans, int m_index){
    
    long long result = 0;
    vector<long long> dp(sans.size(), 0);
    int start = 0;
    for(int i = 1; i<sans.size(); i++)
    {
        for(int j = 0; j<i; j++)
        {
            if(sans[j] < sans[i])
            {
                dp[i] = (dp[i] < (dp[j] + 1000000)) ? dp[j] + 1000000 : dp[i];
            }
            
        }
    }

    result = dp[m_index] + 1000000 + *max_element(dp.begin(), dp.end()) + sans[max_element(dp.begin(), dp.end()) - dp.begin()];

    return result;
}

int main() {
    
    int q;
    vector<int> sans;
    cin >> q;

    for(int i = 0; i<q; i++)
    {
        int ques;
        cin >> ques;
        if(ques == 100)
        {
            int n;
            cin >> n;
            for(int j = 0; j<n; j++){
                int temp;
                cin >> temp;
                sans.push_back(temp);
            }
        }else if(ques == 200)
        {
            int h;
            cin >> h;
            sans.push_back(h);
        }else if(ques == 300)
        {
            sans.pop_back();
        }else if(ques == 400)
        {
            int m_index;
            cin >> m_index;
            m_index--;
            cout << plays(sans, m_index) << "\n";
        }
    }

    return 0;
}