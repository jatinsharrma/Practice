/**
* @author Jatin Sharma
* @date 28 June 2024
* @problem https://leetcode.com/problems/maximum-total-importance-of-roads/?envType=daily-question&envId=2024-06-28
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * @class Solution
 * @brief Class that calculates the maximum total importance of roads.
 */
class Solution {
public:
    /**
     * @brief Calculates the maximum total importance of roads.
     * @param n The number of cities.
     * @param roads A vector of vectors representing the roads between cities.
     * @return The maximum total importance of roads.
     */
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> count (n,0);
        for(int i=0 ; i<roads.size() ; i++)
        {
            count[roads[i][1]]++;
            count[roads[i][0]]++;
        }
        sort(count.rbegin(),count.rend());
        long long result = 0;
        for(int i:count)
        {
            result += (long long) i*n;
            n--;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> roads {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};
    int n = 5;
    cout << sol.maximumImportance(n,roads) << endl;
    return 0;
}