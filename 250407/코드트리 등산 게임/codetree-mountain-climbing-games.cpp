#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int get_max(vector<int> segment_tree, int a, int b)
{
    if (a == b) return segment_tree[a];
    else if (b - a == 1) return segment_tree[a] < segment_tree[b] ? segment_tree[b] : segment_tree[a];

    int mid = (a + b) / 2;

    int leftmax = get_max(segment_tree, a, mid);
    int rightmax = get_max(segment_tree, mid + 1, b);

    return leftmax < rightmax ? rightmax : leftmax;
}


long long plays(vector<int> sans, int m_index) {

    long long result = 0;
    vector<int> dp(sans.size(), 0);
    vector<int> segment_tree(1000000, -1);
    int start = 0;
    for (int i = 0; i < sans.size(); i++)
    {
        //dp[i] = *max_element(segment_tree.begin(), segment_tree.begin() + sans[i]) + 1;
        dp[i] = get_max(segment_tree, 0, sans[i] - 1) + 1;
        segment_tree[sans[i]] = dp[i];
        //cout << "dp["<<i<<"] : "<<dp[i]<<endl;
    }

    result = 1000000 * (dp[m_index] + 1 + *max_element(dp.begin(), dp.end())) + sans[max_element(dp.begin(), dp.end()) - dp.begin()];

    return result;
}

int main() {

    int q;
    vector<int> sans;
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
        }
        else if (ques == 200)
        {
            int h;
            cin >> h;
            sans.push_back(h);
        }
        else if (ques == 300)
        {
            sans.pop_back();
        }
        else if (ques == 400)
        {
            int m_index;
            cin >> m_index;
            m_index--;
            cout << plays(sans, m_index) << "\n";
        }
    }

    return 0;
}

