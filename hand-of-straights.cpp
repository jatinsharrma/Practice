// https://leetcode.com/problems/hand-of-straights/?envType=daily-question&envId=2024-06-06

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        ios_base::sync_with_stdio(0) ; cin.tie(0); cout.tie(0);
        int n = hand.size();
        if (n<groupSize) return false;

        int a[n];
        memset(a,-1,sizeof(a));

        sort(hand.begin(),hand.end());

        int i=0 , j=0 ;
        int count = 0;
        while(j<n)
        {
            if (a[i] == 0 && count == 0) {i++ ; j=i; continue;}
            if (a[j] == 0) {j++ ; continue;}
            if(hand[i] + count == hand[j])
            {
                count ++;
                a[j] = 0;
                j++;    
            }
            else j++;
            if (count == groupSize)
            {
                i++;
                count = 0;
                j = i;
            }
        }
        if (count != 0) return false;
        for(int i : a)
            if (i == -1) return false;

        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> hand {1,2,2,3,3,4,6,7,8};
    int groupSize = 3;
    cout << sol.isNStraightHand(hand,groupSize) << endl;
    return 0;
}