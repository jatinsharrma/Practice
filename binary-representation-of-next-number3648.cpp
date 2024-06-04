// https://www.geeksforgeeks.org/problems/binary-representation-of-next-number3648/1

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
  public:
    string binaryNextNumber1(string s) {
        // code here.
        int n = s.size();
        int count = 0;
            for(int j=0; j<n ; j++)
                if(s[j] == '0')
                    count ++;
                else
                    break;
        string temp = s.substr(count,n-count);

        n = temp.size();
        if(n==0) return "1";

        string result = "";
        int i;
        for(i=n-1 ; i>=0 ; i--)
        {
            if (temp[i] == '0') 
            {
                result += "1";
                break;
            }
            result += "0";
                
        }
        reverse(result.begin(), result.end());
        if (i==-1 && temp[0] == '1')
        {
            return "1" + result;
        }
        else
        {
            return s.substr(count,i) + result;
        }
    }


};


int main()
{
    Solution s;
    string str = "000001111100111";
    cout << s.binaryNextNumber(str) << endl;
    return 0;
}
