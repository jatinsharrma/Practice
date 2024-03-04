// https://leetcode.com/problems/product-of-array-except-self/description/

#include <iostream>
#include <vector>

using namespace std;

/**
 * @class Solution
 * @brief Class that calculates the product of an array except for the current element.
 */
class Solution
{
    public:
        /**
         * @brief Calculates the product of an array except for the current element.
         * @param nums The input array of integers.
         * @return The array of products.
         */
        vector<int> productExceptSelf(vector<int> &nums)
        {
            int product = 1;
            int count_0 = 0;
            for(int i: nums)
            {
                if (i != 0) product = product * i;
                else count_0++;
            }
            if (count_0 == nums.size())
                product = 0;
            
            vector<int> result;
            for(int i=0 ; i<nums.size() ; i++)
            {
                if(nums[i] == 0) 
                {
                    if(count_0>1) result.push_back(0);
                    else result.push_back(product);
                }
                else 
                {
                    if (count_0) result.push_back(0);
                    else result.push_back(product/nums[i]);
                }
            }
            return result;
        }
};

int test()
{
    Solution solution;

    // Test case 1: Normal case with positive integers
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> result1 = solution.productExceptSelf(nums1);
    cout << "Test case 1: ";
    for (int num : result1)
    {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2: Normal case with negative integers
    vector<int> nums2 = {-1, -2, -3, -4, -5};
    vector<int> result2 = solution.productExceptSelf(nums2);
    cout << "Test case 2: ";
    for (int num : result2)
    {
        cout << num << " ";
    }
    cout << endl;

    // Test case 3: Array with a zero element
    vector<int> nums3 = {1, 2, 0, 4, 5};
    vector<int> result3 = solution.productExceptSelf(nums3);
    cout << "Test case 3: ";
    for (int num : result3)
    {
        cout << num << " ";
    }
    cout << endl;

    // Test case 4: Array with multiple zero elements
    vector<int> nums4 = {0, 2, 0, 4, 0};
    vector<int> result4 = solution.productExceptSelf(nums4);
    cout << "Test case 4: ";
    for (int num : result4)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

int main()
{
	Solution s;
	vector<int> nums{0,0,4};
	vector<int> result = s.productExceptSelf(nums);

	for(int i=0; i<result.size() ; i++)
	{
		cout << result[i] << "\t" ;
	}
    cout << "\n";
    test();
	return 0;
}
