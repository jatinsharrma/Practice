// https://www.geeksforgeeks.org/problems/sum-of-prime4751/1

/**
 * 
 * except 2 all prime numbers are odd. This means n should be even ( because odd + odd = even ) except if 2 is factor of n.
 * 
 * Primality test idea is from below link
 * https://cp-algorithms.com/algebra/primality_tests.html 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @class Solution
 * @brief Class that provides a method to find the sum of two prime numbers that add up to a given number.
 */
class Solution{
public:
    /**
     * @brief Finds two prime numbers that add up to a given number.
     * @param n The given number.
     * @return A vector containing the two prime numbers that add up to the given number. If no such pair exists, returns {-1, -1}.
     */
    vector<int> getPrimes(int n) {
        // code here
        if (n%2!=0) 
        {
            if (isPrime(n-2))
                return {2,n-2};
            return {-1,-1};
        }
        for(int i=2 ; i<=n/2 ; i++)
        {
            if(isPrime(i) && isPrime(n-i))
                return {i,n-i};
        }
        return {-1,-1};
    }
    
    /**
     * @brief Checks if a number is prime.
     * @param n The number to be checked.
     * @return True if the number is prime, false otherwise.
     */
    bool isPrime(int n)
    {
        for(int d=2 ; d*d<=n ; d++)
            if(n%d == 0) return false;
        return n>=2;
    }
};

int main(){
    Solution sol;
    int n = 10;
    vector<int> result = sol.getPrimes(n);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}