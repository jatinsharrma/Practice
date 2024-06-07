// https://leetcode.com/problems/replace-words/?envType=daily-question&envId=2024-06-07

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution 
{
public:
    string replaceWords(vector<string>& dictionary, string sentence) 
    {
        unordered_map<char,vector<string>> map;
        string result  = "";

        for(string i:dictionary)
        {
            if(!map.contains(i[0])) map[i[0]] = {};
            map[i[0]].push_back(i);
        }

        istringstream iss(sentence);
        string word;

        for(pair i : map)
        {
            for(string j : i.second) cout << i.first << " " << j << endl;
        }

        while(iss>>word)
        {
            if(!map.contains(word[0])) result += word + " ";
            else
            {
                string new_word = word;
                for(string i : map[word[0]])
                {
                    if(word.substr(0,i.size()) == i)
                    {
                        if(i.size() < new_word.size()) new_word = i;
                    }
                }
                result += new_word + " ";
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> dictionary {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery"
;
    cout << sol.replaceWords(dictionary,sentence) << endl;

    return 0;
}