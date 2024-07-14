/**
* @author Jatin Sharma
* @date 9 Juy 2024
* @problem https://leetcode.com/problems/average-waiting-time/description/?envType=daily-question&envId=2024-07-09
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        double ans = 0.0;
        int free = customers[0][0];
        int n = customers.size();
        for(int i=0 ; i<n ; i++)
        {
            if(free < customers[i][0]) free = customers[i][0] + customers[i][1];
            else free += customers[i][1];
            ans += free - customers[i][0];
        }
        return ans/n;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> customers {{1,2},{2,5},{4,3}};
    cout << sol.averageWaitingTime(customers) << endl;
    return 0;
}