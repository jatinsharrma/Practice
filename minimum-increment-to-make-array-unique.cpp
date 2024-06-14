// https://leetcode.com/problems/minimum-increment-to-make-array-unique/

/*
Approach
1. Initialize a variable result=0result=0result=0;
2. Sort the array.
3. Traverse the array, starting from index 1.
    a. check if current index value is equal to previous index value. If yes increment the result by 1 and current index value by 1.
    b. check if current indexx value is less than previous index value (this will/might occure because of point a. ) if yes, increment the result by previous−current+1previous - current + 1previous−current+1 and current index value by same.
4. Return result.
*/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    /**
    * Calculates the minimum number of increments required to make the given array unique.
    *
    * @param nums The input array of integers.
    * @return The minimum number of increments required.
    */
    int minIncrementForUnique(vector<int>& nums) {
        ios_base::sync_with_stdio(0) ; cin.tie(nullptr);
        sort(nums.begin(),nums.end());
        int inc = 0;
        int n = nums.size();
        for(int i=1 ; i<n ; i++)
        {
            if(nums[i-1] == nums[i] )
            {
                inc += 1 ;
                nums[i] += 1;
            }
            else if (nums[i-1]>nums[i])
            {
                int diff = nums[i-1] - nums[i] + 1;
                inc += diff ;
                nums[i] +=diff;
            }
        }
        return inc;
    }
};

int main()
{
    Solution sol;
    vector<int> nums {1,2,2};
    cout << sol.minIncrementForUnique(nums) << endl;
    return 0;
}