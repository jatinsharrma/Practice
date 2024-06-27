/**
* @author Jatin Sharma
* @date 27 June 2024
* @problem https://www.geeksforgeeks.org/problems/toeplitz-matrix/1
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * @class Solution
 * @brief Class that checks if a matrix is a Toeplitz matrix.
 */
class Solution{
public:
    /**
     * @brief Checks if the given matrix is a Toeplitz matrix.
     * @param mat The matrix to be checked.
     * @return True if the matrix is a Toeplitz matrix, false otherwise.
     */
    bool isToeplitz(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(mat[i-1][j-1] != mat[i][j]) return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat {{1,2,3},{0,1,2},{4,0,1}};
    cout << sol.isToeplitz(mat) << endl;
    return 0;
}