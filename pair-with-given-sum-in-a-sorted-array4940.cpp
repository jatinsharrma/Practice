/**
* @author Jatin Sharma
* @date 2 Jan 2025
* @problem https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

class Solution{
  public:
    /**
     * @brief Counts the number of pairs in a sorted array that sum up to a given target.
     * 
     * This function takes a sorted array and a target sum, and returns the number of unique pairs
     * in the array that add up to the target sum. It uses an unordered map to keep track of the 
     * frequency of each element in the array.
     * 
     * @param arr A reference to a vector of integers representing the sorted array.
     * @param target An integer representing the target sum.
     * @return An integer representing the number of pairs that sum up to the target.
     */
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        unordered_map<int,int> mp;
        int res = 0;
        for(int i:arr)
            mp[i]++;
        
        for(int i:arr)
        {
            mp[i]--;
            int diff = target - i;
            if(mp.count(diff))
            {
                if(mp[diff])
                {
                    res += mp[diff];
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 1, 2, 2, 2, 3, 4, 4, 4, 5};
    int target = 5;
    cout << sol.countPairs(arr, target) << endl;
    return 0;
}