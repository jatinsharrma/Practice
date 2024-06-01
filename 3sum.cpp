// https://leetcode.com/problems/3sum/

#include <iostream>
#include <vector>

using namespace std;

/**
    * Finds all unique triplets in the given array that sum up to zero.
    *
    * @param nums The input array of integers.
    * @return A vector of vectors containing the unique triplets.
    */
class Solution {
public:
    /**
     * Finds all unique triplets in the given vector that sum up to zero.
     * Time complexity: O(n^3)
     * Space complexity: O(1)
     * @param nums The input vector of integers.
     * @return A vector of vectors, where each inner vector represents a unique triplet that sums up to zero.
     */
    vector<vector<int>> threeSum1(vector<int>& nums) {
        vector<vector<int>> result;
        for(int i=0; i<nums.size();i++)
        {
            for(int j=i+1 ; j<nums.size(); j++)
            {
                for(int k=j+1 ; k<nums.size(); k++)
                {
                    if (nums[i]+nums[j]+nums[k]==0)
                        result.push_back({nums[i],nums[j],nums[k]});
                }
            }
        }
        return result;
    }

    /**
     * Finds all unique triplets in the given vector that sum up to zero.
     * 
     * time complexity O(nlogn) + O(n^2)
     * 
     * @param nums The input vector of integers.
     * @return A vector of vectors, where each inner vector represents a unique triplet that sums up to zero.
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n<3)
            return result;
        for( int i=0 ; i<n-2 ; i++)
        {
            int l = i+1 , r = n-1;
            if(nums[i]>0)
                break;
            if(i>0 && nums[i-1] == nums[i])
                continue;
            while(l<r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                
                if (sum > 0)
                    r--;
                else if ( sum < 0 )
                    l++;
                else{
                    result.push_back({nums[i],nums[l],nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    l++;
                    
                    while (l < r && nums[r - 1] == nums[r]) {
                        r--;
                    }
                    r--;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums {0,0,0,0};
    vector<vector<int>> result = s.threeSum(nums);
    for (auto i:result)
    {
        for(auto j:i)
        {
            cout << j << "\t";
        }
        cout << "\n";
    }
    return 0;
}
