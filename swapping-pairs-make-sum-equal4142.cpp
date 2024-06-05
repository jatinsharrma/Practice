// https://www.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1

#include <iostream>

using namespace std;

/**
 * @class Solution
 * @brief Class that provides a solution for finding swap values to make the sum equal.
 */
class Solution
{
public:
    /**
     * Brute force O(n^2)
     * 
     * @brief Finds swap values in two arrays to make their sum equal.
     * @param a An array of integers.
     * @param n The size of array a.
     * @param b An array of integers.
     * @param m The size of array b.
     * @return 1 if swap values exist, 0 otherwise.
     */
    int findSwapValues1(int a[], int n, int b[], int m) {
        int sum_1 = 0 , sum_2 = 0;
        int i = 0 , j = 0;

        int result = -1;

        while (i<n || j<m)
        {
            if(i<n) sum_1 += a[i];
            if(j<m) sum_2 += b[j];
            i++; j++;
        }
        
        for(int i = 0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(((sum_1 - a[i])+b[j]) == ((sum_2 - b[j])+a[i])) 
                {
                    result = 1;
                    break;
                }
            }
        }

        return result;
    }

    /**
     * 
     * Optimized method : O(nlogn + mlongn + nlogm or mlogn)
     * 
     * (sum1 - a[i]) + b[j] = (sum2 - b[j]) + a[i]
     * sum1 - sum2 = 2(a[i] - b[j])      
     * 
     * So, by second equation we can se the difference will be even (multiplied by 2).
     * 
     * Finds the values to swap between two arrays to make their sums equal.
     *
     * This function takes two arrays, `a` and `b`, along with their sizes `n` and `m` respectively.
     * It calculates the sums of the elements in both arrays and checks if their difference is even.
     * If the difference is not even, it returns -1 indicating that it is not possible to make the sums equal.
     * If the difference is even, it calculates the target value by dividing the difference by 2.
     * The function then sorts both arrays in ascending order.
     * 
     * Now we will do binary search
     * 
     * It iterates through both arrays simultaneously and checks the difference between the current elements.
     * If the difference is equal to the target value, it returns 1 indicating that a swap can be made.
     * If the difference is less than the target value, it increments the index of array `a`.
     * If the difference is greater than the target value, it increments the index of array `b`.
     * If no swap values are found, it returns -1.
     *
     * @param a An array of integers.
     * @param n The size of array `a`.
     * @param b An array of integers.
     * @param m The size of array `b`.
     * @return 1 if swap values are found, -1 otherwise.
     */
    int findSwapValues(int a[], int n, int b[], int m) {
        int sum1 = 0 , sum2 = 0;
        int i = 0 , j = 0;
        int target = 0;

        // sum of two arrays
        while (i<n || j<m)
        {
            if(i<n) sum1 += a[i];
            if(j<m) sum2 += b[j];
            i++; j++;
        }

        // checking if difference is odd
        if ((sum1 - sum2) % 2 != 0)
            return -1;

        target =  ((sum1 - sum2) / 2);

        //sorting
        sort(a, a + n);
        sort(b, b + m);

        i = 0; j = 0;

        // binary search
        while (i < n && j < m) {
            int diff = a[i] - b[j];

            if (diff == target) {
                return 1;
            }

            else if (diff < target)
                i++;
            else
                j++;
        }
        return -1;
    }

};

int main()
{
    Solution sol;
    int a[] = {4, 1, 2, 1, 1, 2};
    int b[] = {3, 6, 3, 3};
    int n = 6;
    int m = 4;

    cout << sol.findSwapValues(a,n,b,m);

    return 0;
}