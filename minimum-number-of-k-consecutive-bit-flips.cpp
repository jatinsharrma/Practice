/**
 * 
 * @author jatin sharma
 * @date 24-June-20224
 * 
 * @problem  https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/?envType=daily-question&envId=2024-06-24
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int minKBitFlips1(vector<int>& nums, int k) {
        int l = 0;
        vector<int> flip(nums.size(),0);
        int count = 0;
        while(l <= nums.size()-k)
        {
            if(nums[l] == 0)
            {
                if(!(flip[l] & 1))
                {
                    count ++;
                    for(int i=l; i<l+k;i++)
                    {
                        flip[i] ++;
                    }
                }
            }
            else{
                if(flip[l] & 1)
                {
                    count ++;
                    for(int i=l; i<l+k;i++)
                    {
                        flip[i] ++;
                    }
                }
            }
            l++;
            for(int i = 0; i< nums.size(); i++) cout << flip[i];
            cout << endl;
        }
        
        for(int i = l ; i< nums.size(); i++)
        {
            if(nums[i] == 0 && !(flip[i] & 1)) return -1;
            if(nums[i] == 1 && (flip[i] & 1)) return -1;
        }
        return count;
    }

    int minKBitFlips(vector<int>& nums, int k) {
        
    }
};

int main()
{
    Solution sol;
    vector<int> nums {0,0,0,1,0,1,1,0};
    int k = 3;
    cout << sol.minKBitFlips(nums,k) << endl;
    return 0;
}