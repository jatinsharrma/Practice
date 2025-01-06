/**
* @author Jatin Sharma
* @date 5 Jan 2025
* @problem https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-less-than-target/1
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
     * @brief Counts the number of pairs in the array whose sum is less than the given target.
     * 
     * This function sorts the input array and uses a two-pointer technique to count the number of pairs
     * whose sum is less than the specified target value.
     * 
     * @param arr A reference to a vector of integers.
     * @param target An integer representing the target sum.
     * @return int The number of pairs whose sum is less than the target.
     */
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        /*
        [ 2 3 5 7 ] target is 8
        for example i = 0  and j = 2, arr[i] + arr[j] = 7 < target 
        so all pairs kepping i fixed and j < 2 will be less than target i.e [2,3] [2,5] 
        */
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int i=0,j=n-1;
        int ans=0,res=0;
        while(i < j && i<n && j>=0)
        {
            if((arr[i] + arr[j]) >= target) j--;
            else{
            ans = (j-i);
            res += (ans);
            i++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 3, 7, 9, 11, 14, 16};
    int target = 10;
    cout << sol.countPairs(arr, target) << endl;
    return 0;
}