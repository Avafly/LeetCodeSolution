
// LeetCode Problem:
// Title: Insert Interval
// URL: https://leetcode.com/problems/insert-interval/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        // insert newInterval in the appropriate position
        int numsSize = intervals.size();
        for(int i = 0; i < numsSize; ++i) {
            if(intervals[i][0] > newInterval[0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
        }
        if(intervals.size() == numsSize) {
            intervals.push_back(newInterval);
        }

        vector<vector<int>> ans;
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
        {1, 3},
        {2, 2},
        {2, 3},
        {2, 2},
        {3, 3},
        {4, 6},
        {5, 7},
    };
    vector<int> newInterval = {6, 10};

    vector<vector<int>> ans = sol.insert(intervals, newInterval);

    for(auto &entry : ans) {
        for(auto &num : entry) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}