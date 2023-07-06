#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i < intervals.size(); ++i) {
            // non-overlapping intervals, add to the result
            if(intervals[i][0] > end) {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            // overlapping intervals, merge them
            else {
                end = max(end, intervals[i][1]);
            }
        }

        ans.push_back({start, end});
        
        return ans;
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();
    vector<vector<int>> intervals = {
        {0, 0},
        {2, 3},
        {2, 2},
        {3, 3},
        {1, 3},
        {5, 7},
        {2, 2},
        {4, 6},
    };

    vector<vector<int>> ans = sol.merge(intervals);

    for(auto &entry : ans) {
        for(auto &num : entry) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}