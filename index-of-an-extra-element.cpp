//

#include <iostream>

using namespace std;

class Solution
{
public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
        if(arr1[0] != arr2[0]) return 0;
        if(arr1[n-1] != arr2[n-2]) return n-1;
        int i = 0, j=n-1;
        while(i<j)
        {
            cout << i << " " << j << endl;
            int mid = (j+i)/2;
            if(arr1[mid] == arr2[mid])
            {
                i = mid+1;
            }
            else
            {
                if (arr1[mid-1] == arr2[mid-1])
                    return arr1[mid];
                else
                {
                    j = mid -1;
                }
            }
        }
        return arr1[i];
    }
};

int main()
{
    Solution sol;
    int n = 7;
    int arr1[] = {2, 4, 6, 8, 9, 10, 12};
    int arr2[] = {2, 6, 8, 9, 10, 12};
    cout << sol.findExtra(n,arr1,arr2) <<endl;
    return 0;
}