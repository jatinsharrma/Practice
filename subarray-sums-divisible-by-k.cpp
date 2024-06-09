// https://leetcode.com/problems/subarray-sums-divisible-by-k/description/?envType=daily-question&envId=2024-06-09

#include <iostream>
#include <unordered_map>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
private:
    unordered_map<int,int> map;
    int count = 0;

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
    int helper(vector<int> &nums, int l, int r , int k , int sum)
    {
        cout << l << " " << r << " " << sum << endl;
        if(r-l==0)
        {
            if(sum%k == 0) {count++ ;return true;}
            else {return false;}
        } 
        if(sum%k == 0) {count++ ;}
        bool a = helper(nums, l+1,r,k,sum-nums[l]);
       
        bool b = helper(nums,l,r-1,k,sum-nums[r]);
        
        return false;
    }
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        this->helper(nums,0,n-1,k,sum);
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> nums {4,5,0,-2,-3,1};
    int k = 5;
    cout << sol.subarraysDivByK(nums,k);
}