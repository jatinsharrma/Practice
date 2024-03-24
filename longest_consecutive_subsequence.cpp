// https://leetcode.com/problems/longest-consecutive-sequence/description/

#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
	int longestConsecutive(vector<int>& nums)
	{
            if(nums.size() == 0) return 0;
			//int smallest = numeric_limits<int>::max() , largest = 0;
            int smallest = 1000000000 , largest = 0;

			for(int i : nums)
			{
				if (i < smallest) smallest = i;
				if (i > largest) largest = i;
			}	
            int offset = abs(smallest);
            
            vector<int> sequence(offset+largest+1,0);

			for(int i : nums)
			{
				sequence[offset+i] = 1;
			}

			int result = 0;
			int temp = 0;
			for (int i : sequence)
			{
				if (i == 1) temp++;
				else
				{
					if (temp > result) result = temp;
					temp = 0;
				}
			}
            if (result < temp ) result = temp;
			return result;
	}
	int longestConsecutive1(vector<int>& nums)
	{
		unordered_map<int,int> mp;
		for(int i : nums)
		{
			if (mp.contains(i)) mp[i]++;
			else mp[i] = 1;
		}
		int longest = 0;

		unordered_map<int,int> v_mp;
		for(auto i: mp)
		{
			if(v_mp.contains(i.first))
			{
				continue;
			}

			bool flag1 = false;
			bool flag2 = false;
			int count = 0;
			int num1 = i.first;
			int num2 = i.first;
			num2--;
			while(1)
			{
				if (mp.contains(num1)) {v_mp[num1]=1; count ++; num1++;}
				else flag1 = true;
				if (mp.contains(num2)) {v_mp[num2]=1; count ++; num2--;}
				else flag2 = true;
				if (flag1 && flag2) break;
			}
			if (count > longest) longest = count;

		}
		return longest;
	}

	int longestConsecutive2(vector<int>nums)
	{
		int n = nums.size();
        if(n==0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int longest = 1;
        int currcnt = 1;
        int smallest = INT_MIN;

        for(int i =0; i<n-1; i++){
			cout << nums[i] << "\t" << nums[i+1] << "\n";
            if((nums[i]+1)==nums[i+1])
			{
				currcnt++;
			}
			else if(nums[i]==nums[i+1]) continue;
			else
			{
				if (currcnt>longest) longest=currcnt;
				currcnt=1;
			}
        }
		if (currcnt>longest) longest=currcnt;
        return longest;

	}
};

int test()
{
    Solution solution;

    // Test case 1: Empty vector
    std::vector<int> nums1;
    int result1 = solution.longestConsecutive(nums1);
    assert(result1 == 0);

    // Test case 2: Vector with consecutive elements
    std::vector<int> nums2 = {1, 2, 3, 4, 5};
    int result2 = solution.longestConsecutive(nums2);
    assert(result2 == 5);

    // Test case 3: Vector with non-consecutive elements
    std::vector<int> nums3 = {5, 2, 8, 1, 4};
    int result3 = solution.longestConsecutive(nums3);
    assert(result3 == 2);

    // Test case 4: Vector with negative elements
    std::vector<int> nums4 = {-3, -1, -2, 0, -4};
    int result4 = solution.longestConsecutive(nums4);
    assert(result4 == 5);

    std::cout << "All test cases passed!" << std::endl;

    return 0;
}

int main()
{
	Solution s;
	vector<int> nums {0,3,7,2,5,8,4,6,0,1};
	cout << s.longestConsecutive2(nums) << "\n";
    test();
	return 0;
}
