/**
* @author Jatin Sharma
* @date 9 Aug 2024
* @problem https://leetcode.com/problems/magic-squares-in-grid/?envType=daily-question&envId=2024-08-09
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0; i< grid.size()-2; i++)
        {
            for(int j=i; j<grid[0].size()-2; j++)
            {
                int n_1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                int n_2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
                int n_3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
                int d_1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
                int d_2 = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
                if(n_1==n_2 && n_2==n_3 && n_3 == d_1 && d_1 == d_2)
                    ans ++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid {{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    vector<vector<int>> grid2 {{4}};

    // cout << sol.numMagicSquaresInside(grid) << endl;
    cout << sol.numMagicSquaresInside(grid2) << endl;

    return 0;
}