// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0,j=0;
        int max_p = 0;
        while (j<prices.size())
        {
            if (prices[j] >= prices[i])
            {
                max_p = max(prices[j]-prices[i],max_p);
            }
            else
            {
                i=j;
            }
            j++;
        }
        return max_p;
    }
};

int test() {
    Solution s;
    // Test case 1: prices are in ascending order
    vector<int> prices1 = {1, 2, 3, 4, 5};
    assert(s.maxProfit(prices1) ==4); // Expected output: 4

    // Test case 2: prices are in descending order
    vector<int> prices2 = {5, 4, 3, 2, 1};
    assert(s.maxProfit(prices2) == 0); // Expected output: 0

    // Test case 3: prices have a peak in the middle
    vector<int> prices3 = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    assert(s.maxProfit(prices3) == 4);// Expected output: 4

    // Test case 4: prices have a valley in the middle
    vector<int> prices4 = {5, 4, 3, 2, 1, 2, 3, 4, 5};
    assert(s.maxProfit(prices4)==4); // Expected output: 4

    // Test case 5: prices have multiple peaks and valleys
    vector<int> prices5 = {1, 2, 1, 2, 1, 2, 1, 2, 1};
    assert(s.maxProfit(prices5)==1); // Expected output: 1
    std::cout << "All test cases passed!" << endl;
    return 0;
}

int main()
{
    Solution s;
    vector<int> prices={2,1};
    cout << s.maxProfit(prices) << "\n";
    test();
    return 0;
}