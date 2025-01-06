/**
* @author Jatin Sharma
* @date 4 Jan 2025
* @problem https://www.geeksforgeeks.org/problems/count-all-triplets-with-given-sum-in-sorted-array/1
* Taken help from comments
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
     * @brief Counts the number of triplets in a sorted array that sum up to a given target.
     * 
     * This function takes a sorted array and a target sum, and returns the number of unique triplets
     * (i, j, k) such that arr[i] + arr[j] + arr[k] equals the target sum.
     * 
     * @param arr A reference to a vector of integers representing the sorted array.
     * @param target An integer representing the target sum for the triplets.
     * @return int The number of triplets that sum up to the target value.
     */
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        unordered_map<int, int> mp;
        for (int e : arr) {
            mp[e]++;
        }
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]]--; 
            for (int j = 0; j < i; j++) { 
                int temp = target - arr[i] - arr[j];
                if (mp.find(temp) != mp.end()) {
                    res += mp[temp];
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 9;
    cout << sol.countTriplets(arr, target) << endl;
    return 0;
}