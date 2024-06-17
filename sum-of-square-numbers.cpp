// https://leetcode.com/problems/sum-of-square-numbers/submissions/1291732538/?envType=daily-question&envId=2024-06-17

#include <iostream>
#include <cmath>

using namespace std;

/**
 * @class Solution
 * @brief Class that provides a solution for determining if a given number can be expressed as the sum of two square numbers.
 */
class Solution{
private:
    /**
     * @brief Checks if a number is a perfect square.
     * @param n The number to check.
     * @return True if the number is a perfect square, false otherwise.
     */
    bool isPerfectSquare(long long n){
        if(n>=0){
            long long s = sqrt(n);
            if(s*s == n) return true;
        }
        return false;
    }
public:
    /**
     * @brief Determines if a given number can be expressed as the sum of two square numbers.
     * @param c The number to check.
     * @return True if the number can be expressed as the sum of two square numbers, false otherwise.
     */
    bool judgeSquareSum(int c) {
        long long n = sqrt(c)+1;
        for(long long i=0 ; i<=n ; i++)
        {
            long long temp = i*i;
            if(isPerfectSquare(temp))
            {
                if(isPerfectSquare(c - temp)) return true;
            }
        }
        return false;
    }

    /**
     * 
     * Better than above, takes less time.
     * 
     * @brief Determines if a given number can be expressed as the sum of two square numbers.
     * @param c The number to check.
     * @return True if the number can be expressed as the sum of two square numbers, false otherwise.
     */
    bool judgeSquareSum2(int c) {
        long long a=0, b=pow(c, 0.5);

        while(a<=b){
            long long s = a*a+b*b;
            if(s==c)return true;
            else if(s>c)b--;
            else a++;
        }
        
        return false;
    }
};

int main()
{
    Solution sol;
    int c = 74;
    cout << sol.judgeSquareSum(c) << endl;
    return 0;
}