// https://www.geeksforgeeks.org/problems/trail-of-ones3242/1

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution{   
    public:
    const int MOD = 1e9 + 7;

int numberOfConsecutiveOnes(int n) {
  if (n <= 0) {
    return 0;
  }

  // Initialize DP table with modulo operation
  int dp[n];
  dp[0] = 1;  // One valid combination (all zeros)

  // Build DP table with modulo operation
  for (int i = 1; i < n; ++i) {
    dp[i] = dp[i - 1] % MOD;  // Ending in 0
    if (i > 1) {
      dp[i] = (dp[i] + dp[i - 2]) % MOD;  // Ending in 1 (if not the first bit)
    }
  }

  return dp[n - 1] % MOD;  // Final result modulo MOD
}
};
int main()
{
	Solution s;
	int n = 55;
	cout << s.numberOfConsecutiveOnes(n) << endl;
	return 0;
}
