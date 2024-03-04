// https://leetcode.com/problems/top-k-frequent-elements/
// requrie C++ 20


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * @brief This class provides a solution to find the top k frequent elements in a given vector of integers.
 */
class Solution {
public:
    /**
     * @brief Finds the top k frequent elements in the given vector.
     * This a brute force solution with O(nlogn) time complexity.
     * 
     * @param nums The vector of integers.
     * @param k The number of top frequent elements to find.
     * @return The vector containing the top k frequent elements.
     */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> mp;
        for (int i : nums)
        {
            if (mp.contains(i)) mp[i]++;
            else mp[i] = 1;
        }
        vector<pair<int,int>> temp;
        for (auto i:mp)
        {
            temp.push_back(i);
        }
        sort(temp.rbegin(),temp.rend(),compare);
        for(int i=0 ; i<k ;i++) result.push_back(temp[i].first);
        return result;
    }


    vector<int> topKFrequent2(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int i : nums)
        {
            if (mp.contains(i)) mp[i] ++;
            else mp[i] = 1;
        }

        vector<vector<int>> arr(nums.size()+1);
        vector<int> result;

        for(auto i: mp)
        {
            arr[i.second].push_back(i.first);
        }

        for (int i=nums.size() ; i>=0 ; i-- )
        {
            if(arr[i].size() !=0 && k>0)
            {
                result.reserve(result.size()+arr[i].size());
                result.insert(result.end(),arr[i].begin(),arr[i].end());
                k = k - arr[i].size();
            }
        }
        return result;
        
    }
    
    /**
     * @brief Comparator function used for sorting the elements in descending order of their frequencies.
     * 
     * @param n The first pair of integers.
     * @param m The second pair of integers.
     * @return True if the frequency of the first pair is less than the frequency of the second pair, False otherwise.
     */
    static bool compare(pair<int, int>& n,pair<int, int>& m)
    {
      return n.second < m.second;
    }
};

int main()
{
    Solution s;
    
    vector<int> list {1,1,1,2,2,3};
    int k = 3;
    
    vector<int> result = s.topKFrequent2(list,k);

    for(int i:result)
        cout << i << " ";
    cout << "\n";
}