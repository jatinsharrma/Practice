// https://www.geeksforgeeks.org/problems/help-nobita0532/1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string oddEven(string s) {
        // code here
        ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
        int alpha[27];
        memset(alpha,0,sizeof(alpha)); 
        for(char i:s)
        {
            alpha[i%96]++;
        }
        int x = 0;
        int y = 0;
 
        for(int i=1 ; i<27 ; i++)
        {
            if(alpha[i] == 0) continue;
            if(i%2 == 0 && alpha[i]%2 == 0) x++;
            else if (i%2 !=0 && alpha[i]%2 != 0) y++;
        }
        if((x+y)%2==0) return "EVEN";
        
        return "ODD";
    }
};

int main()
{
    Solution sol;
    string s = "dgamrakmk";
    cout << sol.oddEven(s) << endl;
    return 0;
}