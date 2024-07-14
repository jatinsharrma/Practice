/**
* @author Jatin Sharma
* @date  7 Jul 2024
* @problem https://leetcode.com/problems/set-matrix-zeroes/
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
    * Sets the elements in the matrix to zero based on the presence of zero in the matrix.
    * 
    * @param matrix The input matrix.
    */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        int r = matrix.size();
        int c = matrix[0].size();
        for(int i=0 ; i<r ; i++)
        {
            for(int j=0 ; j<c ; j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(!row.contains(i)) row[i] = 0;
                    if(!col.contains(j)) col[j] = 0;
                }
            }
        }
        for(auto i:row)
        {
            for(int j=0 ; j<c ; j++)
                matrix[i.first][j] = 0;
        }
        for(auto i:col)
        {
            for(int j=0 ; j<r ; j++)
                matrix[j][i.first] = 0;
        }
    }

    /**
     * Solution using no extra space
     */
    void setZeroes2(vector<vector<int>>& matrix) {
        int col0 = 1;
        int r = matrix.size();
        int c = matrix[0].size();
        for(int i=0 ; i<r ; i++)
        {
            for(int j=0 ; j<c ; j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(j!=0)
                        matrix[0][j]=0;
                    else
                        col0 = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i=1 ; i<r ; i++)
        {
            for(int j=1 ; j<c ; j++)
            {
                if(matrix[i][j] != 0)
                {
                    if (matrix[0][j] == 0 || matrix[i][0] == 0)
                        matrix[i][j] = 0;
                }
            }
        }
        if(matrix[0][0] == 0)
        {
            for(int i=0 ; i<c ; i++)
                matrix[0][i] = 0;
        }
        if (!col0)
        {
            for(int i=0 ; i<r ; i++)
                matrix[i][0] = 0;
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix {{1, 1, 1},{1, 0, 1},{1, 1, 1}};
    sol.setZeroes2(matrix);
    for(vector<int> i : matrix)
    {
        for(int j : i)
            cout << j << " ";
        cout << endl;
    } 
    return 0;
}