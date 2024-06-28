/**
* @author Jatin Sharma
* @date 28 June 2024
* @problem https://www.geeksforgeeks.org/problems/the-palindrome-pattern3900/1
*/

#include <iostream>
#include <vector>

using namespace std;


/**
 * @class Solution
 * @brief Class that contains the solution for finding the palindrome pattern in a 2D vector.
 */
class Solution {
  public:
    /**
     * @brief Finds the palindrome pattern in the given 2D vector.
     * @param arr The input 2D vector.
     * @return A string representing the position of the palindrome pattern. If no pattern is found, returns "-1".
     */
    string pattern(vector<vector<int>> &arr) {
        int column = -1;
        int n = arr.size();
        int m = arr[0].size();
        int max = n;
        if (m>max) max = m;
        
        for(int i=0 ; i<max ; i++)
        {
            bool flag = false;
            // rows
            if(i<n)
            {
                for(int j=0 ; j<m/2 ; j++)
                {
                    if(arr[i][j] != arr[i][m-j-1])
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                    return to_string(i) + " R";
            }
            flag = false;
            // colums
            if(i<m && column == -1)
            {
                for(int j=0 ; j<n/2 ; j++)
                {
                    if(arr[j][i] != arr[n-j-1][i])
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                    column = i;
            }
        }
        if(column != -1)
            return to_string(column) + " C";
        return to_string(-1);
        
    }
};


//{ Driver Code Starts.

int main() {

    Solution sol;
    vector<vector<int>> arr {{0, 0, 1, 0, 1} ,{1, 1, 0, 0, 1}, {0, 0, 1, 1, 1} ,{1, 1, 0, 0, 0}, {0, 0, 1, 0, 1}};
    cout << sol.pattern(arr) <<endl;
    return 0;
}
// } Driver Code Ends