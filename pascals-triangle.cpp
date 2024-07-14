/**
* @author Jatin Sharma
* @date 7 Jul 2024
* @problem https://leetcode.com/problems/pascals-triangle/description/
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * @class Solution
 * @brief Class that generates Pascal's triangle up to a given number of rows.
 */
class Solution {
public:
    /**
     * @brief Generates Pascal's triangle up to the specified number of rows.
     * @param numRows The number of rows to generate in Pascal's triangle.
     * @return A vector of vectors representing Pascal's triangle.
     */
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if (numRows == 1) return ans;
        int curr_row = 2;
        while(curr_row<=numRows)
        {
            vector<int> temp;
            temp.push_back(1);
            for(int i=0 ; i< ans[curr_row - 2].size()-1; i++)
                temp.push_back(ans[curr_row-2][i]+ans[curr_row-2][i+1]);
            temp.push_back(1);
            ans.push_back(temp);
            curr_row ++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> ans = sol.generate(5);
    return 0;
}