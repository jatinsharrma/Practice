// https://www.geeksforgeeks.org/problems/construct-list-using-given-q-xor-queries/1

#include <iostream>
#include <vector>

using namespace std;

/**
 * @class Solution
 * @brief Class that provides methods to construct a list using given XOR queries.
 */
class Solution {
  public:
  /**
     * @brief Constructs a list based on the given XOR queries.
     * @param q The number of queries.
     * @param queries The vector of queries.
     * @return The constructed list.
     */
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        vector<int> result {0};
        int x_r = 0;
        for( int i=0 ; i< q ; i ++)
        {
            if (queries[i][0] == 0)
            {
                result.push_back(queries[i][1]);
            }
        }

        int num = result.size()-1;

        for(int i=q-1 ; i>=0 ; i--)
        {
            if (queries[i][0] == 1)
            {
                x_r ^= queries[i][1];
            }
            else
            {
                result[num] ^= x_r;
                num --;
            }
        }
        result[0] ^= x_r;
        
        sort(result.begin(),result.end());
        return result;
    }

    /**
     * @brief Constructs a list based on the given XOR queries.
     * @param q The number of queries.
     * @param queries The vector of queries.
     * @return The constructed list.
     */
    vector<int> constructList1(int q, vector<vector<int>> &queries) {
        // code here
        vector<int> result {0};
        int x_r = 0;
        for( int i=0 ; i< q ; i ++)
        {
            if (queries[i][0] == 0)
            {
                if (x_r != 0)
                    for(int j=0 ; j<result.size(); j++)
                        result[j] ^= x_r;
                x_r = 0;
                result.push_back(queries[i][1]);
            }
            else
                x_r ^= queries[i][1];
               
        }
        if (x_r != 0)
            for(int j=0 ; j<result.size(); j++)
                result[j] ^= x_r;
        
        sort(result.begin(),result.end());
        return result;
    }
};

int main()
{
    vector<vector<int>> queries {{0,1},{1, 3},{0, 4},{1, 1},{0, 1},{0, 2},{0, 5},{0, 10},{0, 1},{0,9}};
    Solution s;
    vector<int> result = s.constructList(queries.size(),queries);
    for(int i=0 ; i<queries.size()-1; i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
