//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <map>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        /*
            1. a ^ b = c
            2. a ^ c = b
            3. a ^ 0 = a
            
            4 2 2 6 4
              i   j
            
            logic : if a ^ k = b this means a ^ b = k, where a is currXOR and b 
            is olderXOR and k is given.
            a is XOR from 0-j, b is XOR from 0-(i-1), so when we do a^b, a already 
            have b in it so XORing with b will remove b from a leaving c i.e  XOR 
            from i - j.
            
            why add res with map value?
            example : till index 0 - 3 we have seen 4 2 times. 
            So if i remove 4 (XOR is 4) i get 2 2 6 which is a match,
            if i remove 4 2 2  (XOR is 4 ) i get 6 which is again a match. 
            his is why we have count of 4 = 2 in map.
            
            1. 4 ^ 0 = 4, Now check 4 ^ 6 (which is k) present in map 
                if yes increment res, save 4 = 1
            2. 4 ^ 2 = 6, Now check 6 ^ 6 (which is k) present in map 
                if yes increment res, save 6 = 1
                
            Similarly rest.
        */
        
        long res = 0;
        map<int,int> mp;
        long currXOR = 0;
        mp[0] = 1;
        for(int i:arr)
        {
            currXOR ^= i;
            if(mp.count(currXOR^k))
            {
                res += mp[currXOR^k];
            }
            mp[currXOR] ++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    Solution sol;
    vector<int> arr {4, 2, 2, 6, 4};
    int k = 6;
    cout << sol.subarrayXor(arr, k) << endl;
    return 0;
}
// } Driver Code Ends