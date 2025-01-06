/**
* @author Jatin Sharma
* @date 3 Jan 2025
* @problem https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1
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
     * @brief Counts the number of subarrays with a given sum k.
     * 
     * This function takes a vector of integers and an integer k, and returns the number of subarrays
     * whose elements sum up to k. It uses a prefix sum approach along with a hash map to efficiently
     * count the subarrays.
     * 
     * @param arr A vector of integers representing the array.
     * @param k An integer representing the target sum for the subarrays.
     * @return int The number of subarrays whose sum is equal to k.
     * 
     * @example
     * vector<int> arr = {10, 2, -2, -20, 10};
     * int k = -10;
     * int result = countSubarrays(arr, k); // result will be 3
     */
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        /*
        [ 10, 2 , -2 , -20 , 10] k = -10
        presum = 0 , 10, 12, 10, -10 0
        cnt = 0                   1. 3
        mp[0] = 1
        mp[10] = 2
        mp[12] = 1
        mp[-10] = 1
        */
        map<int, int>mp;
        mp[0] = 1;
        int preSum = 0, cnt = 0;
        for(int i=0; i<arr.size(); i++)
        {
            preSum += arr[i];
            int remove = preSum - k;
            cnt += mp[remove];
            mp[preSum] += 1;
        }
        return cnt;
    }
};

int main()
{
    Solution sol;
    return 0;
}