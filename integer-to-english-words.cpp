/**
* @author Jatin Sharma
* @date 8 Aug 2024
* @problem https://leetcode.com/problems/integer-to-english-words/?envType=daily-question&envId=2024-08-07
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        unordered_map<int,vector<string>> map;
        map[1] = {"Zero ","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine "};
        map[2] = {"Ten ","Eleven ","Tweleve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nienteen "};
        map[3] = {"","","Twenty ","Thirty ","Fourty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};
        vector<string> units {"","Hundered ","Thousand ","Million ","Billion ","Trillion "};
        vector<int> nums;
        int temp = num;
        while(temp)
        {
            nums.push_back(temp%10);
            temp /= 10;
        }
        int n = nums.size()-1;
        string ans = "";
        while(n>=0)
        {
            int temp = ceil((float)n/3);
            int temp2 = n%3 + 1;
            if(temp2 == 1)
            {
                ans += map[1][nums[n]];
                ans += units[temp];
                n--;
            }
            if(temp == 2)
            {
                if(nums[n]<2)
                {
                    ans += map[2][nums[n-1]];
                    ans += units[temp];
                }
                else
                {
                    ans += map[3][nums[n]];
                    ans += map[1][nums[n-1]];
                    ans += units[temp];

                }
                n--;n--;
            }
            else
            {
                ans += map[1][nums[n]];
                ans += units[temp];
                n--;
                if(nums[n]<2)
                {
                    ans += map[2][nums[n-1]];
                }
                else
                {
                    ans += map[3][nums[n]];
                    ans += map[1][nums[n-1]];
                }
                n--;n--;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int num = 1234567;
    cout << sol.numberToWords(num) << endl;
    return 0;
}