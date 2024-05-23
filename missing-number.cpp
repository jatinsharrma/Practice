// https://neetcode.io/problems/missing-number
// https://leetcode.com/problems/missing-number

#include <iostream>
#include <vector>

using namespace std;

/**
 * @class Solution
 * @brief Class that provides solutions for finding missing numbers in an array.
 */
class Solution 
{
public:
    /**
     * @brief Finds the missing number in the given array using the sum formula.
     * @param nums The input array of integers.
     * @return The missing number in the array.
     */
    int missingNumber(vector<int>& nums) 
    {
        int sum = 0, max = 0;
        for (int i : nums)
        {
            sum += i;
            if (i > max)
                max = i;
        }
        int actual_sum = (max*(max+1))/2;
        return actual_sum - sum;
    }

    /**
     * @brief Finds the missing number in the given array using the sum of natural numbers formula.
     * @param nums The input array of integers.
     * @return The missing number in the array.
     */
    int missingNumber2(vector<int>& nums) 
    {
        int sum = 0, n = nums.size(), actual_sum=0;
        for (int i=0 ; i<n ; i++)
        {
            sum += nums[i];
            actual_sum += i + 1;
        }
        return actual_sum - sum;
    }

    /**
     * Calculates the missing number in a vector of integers.
     * 
     * This function takes a vector of integers as input and calculates the missing number
     * by performing bitwise XOR operations on the elements of the vector and the indices.
     * 
     * Most efficient solution.
     * 
     * @param nums The vector of integers.
     * @return The missing number.
     */
    int missingNumber3(vector<int>& nums)
    {
    	int num1 = 0;
	    for (int i: nums)
		    num1 ^= i;
	    int num2 = 0;
	    for (int i=0 ; i<=nums.size();i++)
		    num2 ^= i;
	    return num2 ^ num1;
    }
};

int main()
{
	Solution s;
	vector<int> nums {1,2,3};
	cout << s.missingNumber3(nums);
	return 0;
}
