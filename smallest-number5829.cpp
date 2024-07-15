/**
* @author Jatin Sharma
* @date 15 Jul 2024
* @problem https://www.geeksforgeeks.org/problems/smallest-number5829/1
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        string ans = "";
        // sum greater than 9
        while(s > 9)
        {
            ans += to_string(9);
            s -= 9;
            d --;
            if (d<0) return "-1";
        }
        // sum less than equal to 9 and remaning digits greater than 1
        while(d>1)
        {
            ans = to_string(s-1) + ans;
            s -= s-1;
            d --;
            if (s<0 ) return "-1";
        }
        // digit is 1 
        if(s<=9 && d == 1) {ans = to_string(s) + ans; s = 0; d = 0;}
        if(s!=0 || d!=0) return "-1";
        return ans;
    }
};

int main()
{
    Solution sol;
    int s = 9 , d = 2;
    cout << sol.smallestNumber(s,d) << endl;
    return 0;
}