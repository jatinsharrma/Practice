// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * @class Solution
 * @brief Class that provides solutions for the two sum problem.
 */
class Solution {
public:
/**
     * @brief Finds two numbers in the given vector that add up to the target.
     * @param numbers The vector of integers.
     * @param target The target sum.
     * @return A vector containing the indices of the two numbers that add up to the target.
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        unordered_map<int,int> mp;
        for(int i=0 ;i<numbers.size();i++)
        {
            int diff = target - numbers[i];
            if (mp.contains(diff))
            {
                result.push_back(mp[diff]+1);
                result.push_back(i+1);
                break;
            }
            else mp[numbers[i]] = i;
        }
        return result;
    }


    /**
     * @brief Finds two numbers in the given vector that add up to the target using the two-pointer approach.
     * @param numbers The vector of integers.
     * @param target The target sum.
     * @return A vector containing the indices of the two numbers that add up to the target.
     */
    vector<int> twoSum1(vector<int>& numbers, int target) 
    {
        int i=0,j=numbers.size()-1;
        while(i!=j)
        {
            if(numbers[i]+numbers[j]==target)
            {
                break;
            }
            else if (numbers[i]+numbers[j]>target)j--;
            else i++;
        }
        return {i+1,j+1};
    }
};

int main()
{
	Solution s;
	vector<int> numbers {2,7,11,15};
	int target=9;
	vector<int> result = s.twoSum1(numbers,target);
	for(int i: result) cout << i << "\t";
	cout << "\n";
}
