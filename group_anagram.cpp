// https://leetcode.com/problems/group-anagrams/description/

// require C++20 to compile

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Compares two vectors of strings based on their size.
     * 
     * @param s The first vector of strings.
     * @param t The second vector of strings.
     * @return True if the size of s is less than the size of t, false otherwise.
     */
    static bool compare(vector<string> s, vector<string>t)
    {
        return s.size() < t.size();
    }

    /**
     * Groups anagrams together from a given vector of strings.
     * An anagram is a word formed by rearranging the letters of another word.
     * This function uses a hash map to group anagrams together.
     *
     * @param strs The vector of strings containing the words to group.
     * @return A vector of vectors of strings, where each inner vector represents a group of anagrams.
     */
    vector< vector<string> > groupAnagrams(vector<string>& strs) {
        vector< vector<string> > result;
        unordered_map<string,vector<string> > dict;
        for(string s:strs)
        {
            string temp = s;
            sort(s.begin(),s.end());
            if (dict.contains(s))
                dict[s].push_back(temp);
            else
            {
                vector<string> temp_2 {temp};
                dict[s] = temp_2;
            }
        }
        for (auto i:dict )
        {
            result.push_back(i.second);
        }
        sort(result.begin(),result.end(),this->compare);
        
        for (int i=0 ; i<result.size();i++)
        {
            sort(result[i].begin(),result[i].end());
        }
        return result;
    }
};

int test() {
    // Test Case 1
    Solution s;
    vector<string> input1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector< vector<string> > output1 = s.groupAnagrams(input1);
    cout << "Test Case 1 Output:" << endl;
    for (const auto& group : output1) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Test Case 2
    vector<string> input2 = {"hello", "world", "olleh", "dlrow"};
    vector< vector<string> > output2 = s.groupAnagrams(input2);
    cout << "Test Case 2 Output:" << endl;
    for (const auto& group : output2) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Test Case 3
    vector<string> input3 = {"abc", "def", "ghi", "jkl"};
    vector< vector<string> > output3 = s.groupAnagrams(input3);
    cout << "Test Case 3 Output:" << endl;
    for (const auto& group : output3) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

int main()
{
    Solution s;
    vector<string> input { "eat","tea","tan","ate","nat","bat" };
    s.groupAnagrams(input);
    test();
    return 0;
}