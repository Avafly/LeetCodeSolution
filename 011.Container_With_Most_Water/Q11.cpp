#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int heightSize = static_cast<int>(height.size());
        int iLeft = 0;
        int iRight = heightSize - 1;
        int maxA = min(height[iLeft], height[iRight]) * (iRight - iLeft);
        int area;
        
        // the shorter side generates smaller area, thus the shorter side move to middle for larger area.
        while(iRight-iLeft > 1) {
            if(height[iLeft] < height[iRight]) {
                ++iLeft;
            }
            else {
                --iRight;
            }

            area = min(height[iLeft], height[iRight]) * (iRight - iLeft);
            maxA = max(maxA, area);
        }
        return maxA;
    }
};

int main(int argc, char **argv) {

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    Solution sol;
    cout << sol.maxArea(height) << endl;
    return 0;
}
