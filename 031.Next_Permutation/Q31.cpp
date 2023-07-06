#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k, l = nums.size();

        // retrieve the element smaller than the right-hand elements
        for(k=nums.size()-2; k>-1; k--){
            if(nums[k] < nums[k+1])
                break;
        }
        
        if(k < 0) 
            sort(nums.begin(), nums.end());

        else{
            // retrieve the element that only bigger than nums[k]
            for(l=nums.size()-1; l>k; l--){
                if(nums[k] < nums[l])
                    break;
            }
            swap(nums[k], nums[l]);
            sort(nums.begin()+k+1, nums.end());
        }
    }
};

int main(int argc, char **argv) {

    vector<int> nums = {2,2,7,5,4,3,2,2,1}; // Ans: [2,3,1,2,2,2,4,5,7]

    for(int n : nums) {
        cout << n << " ";
    }
    cout << "\n- - - - -" << endl;

    Solution sol = Solution();
    sol.nextPermutation(nums);

    for(int n : nums) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}