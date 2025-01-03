/**
* @author Jatin Sharma
* @date 25 Jul 2024
* @problem https://leetcode.com/problems/sort-the-jumbled-numbers/?envType=daily-question&envId=2024-07-24
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Better solution, takes less memory and less time
     * 
     * Sorts the jumbled numbers based on the given mapping.
     *
     * @param mapping The mapping of digits to their corresponding values.
     * @param nums The jumbled numbers to be sorted.
     * @return The sorted jumbled numbers.
     */
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        ios_base::sync_with_stdio(0); cin.tie(0);
        vector<pair<int,int>> mapped;
        for(int i=0; i<nums.size(); i++)
        {
            int curr_mapped_value = 0;
            int copy_curr_num = nums[i];
            if(copy_curr_num == 0) mapped.push_back({mapping[0],i});
            else
            {
                int place = 1;
                while(copy_curr_num)
                {
                    curr_mapped_value = place * mapping[copy_curr_num%10] + curr_mapped_value;
                    place *= 10;
                    copy_curr_num /= 10;
                }
                mapped.push_back({curr_mapped_value,i});
            }
        }
        sort(mapped.begin(),mapped.end());
        vector<int> ans;
        for(auto i : mapped)
            ans.push_back(nums[i.second]);
        return ans;
    }

    /**
     * Slow solution, takes more memory and more time.
     * 
     * Sorts the jumbled numbers based on the given mapping.
     *
     * @param mapping The mapping of digits to their corresponding values.
     * @param nums The jumbled numbers to be sorted.
     * @return The sorted jumbled numbers.
     */
    vector<int> sortJumbled2(vector<int>& mapping, vector<int>& nums) {
        ios_base::sync_with_stdio(0); cin.tie(0);
        vector<pair<int,int>> mapped;
        for(int i=0; i<nums.size(); i++)
        {
            int curr_mapped_value = 0;
            int copy_curr_num = nums[i];
            if(copy_curr_num == 0) mapped.push_back({mapping[0],i});
            else
            {
                int place = 1;
                while(copy_curr_num)
                {
                    curr_mapped_value = place * mapping[copy_curr_num%10] + curr_mapped_value;
                    place *= 10;
                    copy_curr_num /= 10;
                }
                mapped.push_back({curr_mapped_value,i});
            }
        }
        sort(mapped.begin(),mapped.end());
        vector<int> ans;
        for(auto i : mapped)
            ans.push_back(nums[i.second]);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> mapping {8,9,4,0,2,1,3,5,7,6};
    vector<int> nums {991,338,38};
    vector<int> ans = sol.sortJumbled(mapping,nums);
    for(int i: ans) cout << i << " ";
    cout << endl;
    return 0;
}