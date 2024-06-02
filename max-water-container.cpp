// https://neetcode.io/problems/max-water-container
// https://leetcode.com/problems/container-with-most-water/description/

#include <iostream>
#include <vector>

using namespace std;

/**
 * @class Solution
 * @brief Class that contains methods to calculate the maximum water container volume.
 */
class Solution {
public:
	/**
	 * Bruetforce
	 * 
	 * @brief Calculates the maximum water container volume using a brute force approach.
	 * @param heights The vector of heights representing the container walls.
	 * @return The maximum water container volume.
	 */
	int maxArea1(vector<int>& heights) 
	{
		int max_vol = 0;
		int n = heights.size();
		for(int i=0 ; i<n ; i++)
		{
			for(int j=i ; j<n ; j++)
			{
				int temp = min(heights[i],heights[j])*abs(i-j);
				if (temp>max_vol)
					max_vol = temp;
			}
		}
		return max_vol;
	}

	/**
	 * @brief Calculates the maximum water container volume using an optimized approach.
	 * @param heights The vector of heights representing the container walls.
	 * @return The maximum water container volume.
	 */
	int maxArea(vector<int>& heights)
	{
		
	}
};

int main()
{
	Solution s;
	vector<int> heights {2,2,2};
	cout << s.maxArea(heights) << endl;
	return 0;
}
