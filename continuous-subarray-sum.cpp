// https://leetcode.com/problems/continuous-subarray-sum/submissions/1281987078/?envType=daily-question&envId=2024-06-08

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

/**
 * @class Solution
 * @brief Class that provides methods to check if there exists a continuous subarray in an array whose sum is a multiple of a given integer.
 */
class Solution {
private:
    unordered_map<int,int> map;

    /**
     * Helper function to check if there exists a continuous subarray in the given vector of integers
     * whose sum is divisible by a given integer.
     *
     * @param nums The vector of integers.
     * @param l The left index of the subarray.
     * @param r The right index of the subarray.
     * @param k The integer to check divisibility with.
     * @param sum The current sum of the subarray.
     * @return True if there exists a continuous subarray whose sum is divisible by k, false otherwise.
     */
    bool helper(vector<int> &nums, int l, int r , int k , int sum)
    {
        if(map.contains(sum)) return false;
        if (sum == 0 ) {return true;}
        if(r-l==1)
        {
             if(sum%k == 0) return true;
            else {map[sum] = 1; return false;}
        } 
        if(sum%k == 0) return true;
        bool a = helper(nums, l+1,r,k,sum-nums[l]);
        if(a) return true;
        bool b = helper(nums,l,r-1,k,sum-nums[r]);
        if(b) return true;
        return false;
    }
public:
    /**
     * Checks if there exists a subarray in the given vector of integers whose sum is a multiple of k.
     *
     * O(nlogn) time complexity
     * 
     * @param nums The vector of integers.
     * @param k The target value.
     * @return True if there exists a subarray whose sum is a multiple of k, false otherwise.
     */
    bool checkSubarraySum1(vector<int>& nums, int k) {
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        if( n==1 && sum==0) return true;
        return this->helper(nums,0,n-1,k,sum);
    }

    /**
     * Checks if there exists a subarray in the given vector of integers whose sum is a multiple of k.
     *
     * O(n) time complexity
     * 
     * @param nums The vector of integers.
     * @param k The target multiple.
     * @return True if there exists a subarray whose sum is a multiple of k, false otherwise.
     */
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = -1;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;
            cout << i << " " << sum << " " << rem << endl;
            if (map.find(rem) != map.end()) {
                if (i - map[rem] > 1) {
                    return true;
                }
            } else {
                map[rem] = i;
            }
        }

        return false;
    }

};

int main()
{
    Solution sol;
    vector<int> nums {1,2,4,5};
    int k = 6;
    cout << sol.checkSubarraySum(nums,k);
}