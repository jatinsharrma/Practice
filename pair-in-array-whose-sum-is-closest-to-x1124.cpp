/**
* @author Jatin Sharma
* @date 6 Jan 2025
* @problem https://www.geeksforgeeks.org/problems/pair-in-array-whose-sum-is-closest-to-x1124/1
* Taken help from comments
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    /**
     * @brief Finds the pair of integers in the array whose sum is closest to the given target.
     * 
     * This function sorts the input array and uses a two-pointer approach to find the pair of integers
     * whose sum is closest to the specified target value. It returns the pair as a vector of two integers.
     * 
     * @param arr A vector of integers representing the input array.
     * @param target An integer representing the target sum.
     * @return A vector of two integers representing the pair whose sum is closest to the target.
     *         If the input array has fewer than 2 elements, an empty vector is returned.
     */
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        /*
            [ 5 10 20 30 ] target 25
            
            Solution : 
                1. Sort the arr, it will help in 2 pointer approch 
                and also help in dealing with a<=b condition.
                2. set closestDiff = +infinity initially. 
                3. if closestDiff > abs(sum - target)
                update closestDiff and also res;
            
        */
        int n = arr.size();
        if (n < 2) {
            return {}; 
        }
        sort(arr.begin(), arr.end());
        vector<int> res;
        int closestDiff = INT_MAX; 

        int i = 0;
        int j = n - 1;
        while (i < j) 
        {
            int sum=arr[i]+arr[j];
            if(closestDiff>abs(sum-target))
            {
                closestDiff=abs(sum-target);
                res = {arr[i],arr[j]};
            }
            if(sum>target)
                j--;
            else
                i++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {10, 22, 28, 29, 30, 40};
    int target = 54;
    vector<int> res = sol.sumClosest(arr, target);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}