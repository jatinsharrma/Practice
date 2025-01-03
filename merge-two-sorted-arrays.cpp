/**
* @author Jatin Sharma
* @date 12 Dec 2024
* @problem https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
  /**
     * @brief Merges two sorted arrays into a single sorted array.
     * 
     * This function takes two sorted vectors `a` and `b`, and merges them such that
     * the elements of both vectors are sorted in non-decreasing order. The function
     * modifies the input vectors in place.
     * 
     * O((n+m)+ mlogm + nlogn) time complexity
     * 
     * @param a A reference to the first sorted vector of integers.
     * @param b A reference to the second sorted vector of integers.
     */
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size() - 1;
        int m = 0;
        while(n>=0 && m<b.size())
        {
            if(a[n] > b[m])
            {
                int temp = a[n];
                a[n] = b[m];
                b[m] = temp;
                n--;
                m++;
            }
            else
            {
                break;
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    }

    /**
     * @brief Merges two sorted arrays into the first array in a sorted manner.
     * 
     * This function takes two sorted vectors, `a` and `b`, and merges elements of `b` into `a` 
     * while maintaining the sorted order. The function modifies the vectors in place.
     * 
     * O(n*m) time complexity
     * 
     * @param a A reference to the first sorted vector which will be merged with the second vector.
     * @param b A reference to the second sorted vector which will be merged into the first vector.
     */
    void mergeArrays2(vector<int>& a, vector<int>& b) {
        // code here
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int m = b.size();
        for(int i=0; i<a.size();i++)
        {
            if (b[0] < a[i])
            {
                int temp = b[0];
                b[0] = a[i];
                a[i] = temp;
                
                int j = 0;
                while(j<m-1)
                {
                    if(b[j]>b[j+1])
                    {
                        int temp = b[j];
                        b[j] = b[j+1];
                        b[j+1] = temp;
                    }
                    else
                        break;
                    j++;
                }
            }
        }
    }
};
int main()
{
    Solution sol;
    return 0;
}