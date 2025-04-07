#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> sans;
vector<int> dp;
vector<int> segment_tree(1000000, -1);

int get_max(int a, int b)
{
    if (a == b) return segment_tree[a];
    else if (b - a == 1) return segment_tree[a] < segment_tree[b] ? segment_tree[b] : segment_tree[a];

    int mid = (a + b) / 2;

    int leftmax = get_max(a, mid);
    int rightmax = get_max(mid + 1, b);

    return leftmax < rightmax ? rightmax : leftmax;
}

void update_dp(void)
{
    for (int i = dp.size(); i < sans.size(); i++)
    {
        //dp[i] = *max_element(segment_tree.begin(), segment_tree.begin() + sans[i]) + 1;
        dp.push_back(get_max(0, sans[i] - 1) + 1);
        segment_tree[sans[i]] = dp[i];
        //cout << "dp["<<i<<"] : "<<dp[i] << ", height : "<<sans[i] << endl;
    }
}


long long plays(int m_index) {

    long long result = 0;

    //update_dp();

    result = 1000000 * (dp[m_index] + 1 + *max_element(dp.begin(), dp.end())) + sans[max_element(dp.begin(), dp.end()) - dp.begin()];

    return result;
}

int main() {

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int ques;
        cin >> ques;
        if (ques == 100)
        {
            int n;
            cin >> n;
            for (int j = 0; j < n; j++) {
                int temp;
                cin >> temp;
                sans.push_back(temp);
            }
            update_dp();
        }
        else if (ques == 200)
        {
            int h;
            cin >> h;
            sans.push_back(h);
            update_dp();
        }
        else if (ques == 300)
        {
            segment_tree[sans[sans.size() - 1]]--;
            sans.pop_back();
            dp.pop_back();
            
        }
        else if (ques == 400)
        {
            int m_index;
            cin >> m_index;
            m_index--;
            cout << plays(m_index) << "\n";
        }
    }

    return 0;
}

