#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Idea: Levenshtein Distance
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int width = word1.size();
        int height = word2.size();
        vector<vector<int>> table(height + 1, vector<int>(width + 1, 0));

        for(int row = 0; row < height + 1; ++row) {
            for(int col = 0; col < width + 1; ++col) {
                if(row == 0) {
                    table[row][col] = col;
                }
                else if(col == 0) {
                    table[row][col] = row;
                }
                else if(word1[col - 1] == word2[row - 1]) {
                    table[row][col] = table[row - 1][col - 1];
                }
                else {
                    table[row][col] = min(min(table[row - 1][col - 1], table[row][col - 1]), table[row - 1][col]) + 1;
                }
            }
        }

        return table[height][width];
    }
};

int main(int argc, char **argv) {
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";

    cout << sol.minDistance(word1, word2) << endl;

    return 0;
}