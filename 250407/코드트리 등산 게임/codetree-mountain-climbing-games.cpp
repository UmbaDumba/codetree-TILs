#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sans;
vector<long long> dp(50000, 0);
int dp_index = 0;

void calculate_dp(int san_max)
{
   
    // dp 뒷부분 더 계산해야함
    for(int i = dp_index; i<san_max; i++)
    {
        for(int j = 0; j<i; j++)
        {
            if(sans[j] < sans[i])
            {
                dp[i] = (dp[i] < (dp[j] + 1000000)) ? dp[j] + 1000000 : dp[i];
            }
            
        }
    }
    dp_index = san_max - 1;
    
}

long long plays(int m_index){
    
    long long result = 0;

    calculate_dp(sans.size());

    result = dp[m_index] + 1000000 + *max_element(dp.begin(), dp.end()) + sans[max_element(dp.begin(), dp.end()) - dp.begin()];

    return result;
}

int main() {
    
    int q;
    
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
            dp[dp_index] = 0;
            dp_index--;
        }else if(ques == 400)
        {
            int m_index;
            cin >> m_index;
            m_index--;
            cout << plays(m_index) << "\n";
        }
    }

    return 0;
}