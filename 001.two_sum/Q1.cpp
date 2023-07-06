#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); ++i) {
            map[nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            int key = target - nums[i];
            if(map[key] != 0 && i != map[key]) return {i, map[key]};
        }

        return {-1, -1};
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {1,3,4,2};
    int target = 6;
    
    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);
    
    for(auto &n : ans) cout << n << " ";
    cout << endl;
    
    return 0;
}