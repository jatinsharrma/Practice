// https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1

#include <iostream>

using namespace std;

class Solution
{
public: 
    long long max_sum(int a[], int n) {
        long long sum = 0;
        for (long long i = 0; i < n; i++) {
            sum += a[i];
        }

        long long initial_val = 0;
        long long max = 0;
        for (long long i = 0; i < n; i++) {
            initial_val += i * a[i];
            max = initial_val;
        }

        for (long long i = 1; i < n; i++) {
            long long temp =
                initial_val - (sum - a[i - 1]) + 1LL * a[i - 1] * (n - 1);
            initial_val = temp;
            if (temp > max)
                max = temp;
        }

        return max;
    }
};

int main()
{
    Solution sol;
    int n = 9;
    int a[] {11, 6, 3, 4, 19, 17, 7, 3, 3};
    cout << sol.max_sum(a,n) <<endl;
    return 0;
}