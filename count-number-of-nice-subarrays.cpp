/**
 * @author Jatin Sharma
 * @date 22 Jun 2024
 * 
 * 
 * @problem : https://leetcode.com/problems/count-number-of-nice-subarrays/description/?envType=daily-question&envId=2024-06-22
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * This class provides a solution for counting the number of nice subarrays in a given array.
 */
class Solution {
public:
    /**
     * Time complexity : O(n)
     * Space complexity : O(n)
     * 
     * @by : @lancertech6
     * 
     * Counts the number of nice subarrays in the given array.
     *
     * @param nums The input array.
     * @param k The number of odd elements required in a subarray to be considered nice.
     * @return The number of nice subarrays.
     */
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        cnt[0] = 1;
        int ans = 0, t = 0;
        for (int v : nums) {
            t += v & 1;
            if (t - k >= 0) {
                ans += cnt[t - k];
            }
            cnt[t]++;
        }
        return ans;
    }

    /**
     * Time complexity O(n^2)
     * Space complexity O(n)
     * 
     * Counts the number of nice subarrays in the given vector of integers.
     * A nice subarray is defined as a subarray that contains exactly 'k' odd numbers.
     *
     * @param nums The vector of integers.
     * @param k The number of odd numbers required in a nice subarray.
     * @return The count of nice subarrays.
     */
    int numberOfSubarrays2(vector<int>& nums, int k) {
        vector<int> odds {0};
        int count = 0;
        for(int i :nums){
            if(i%2 != 0) count ++;
            odds.push_back(count);
        }
        int output = 0;
        for(int i=0 ; i<odds.size()-k;i++){
            for(int j=i+k ; j<odds.size(); j++){
                int temp = odds[j] - odds[i];
                if(temp == k) output ++;
            }
        }
        return output;
    }
};

int main()
{
    Solution sol;
    vector<int> nums {1,1,2,1,1};
    int k = 3;
    cout << sol.numberOfSubarrays(nums,k)<< endl;
    return 0;
}