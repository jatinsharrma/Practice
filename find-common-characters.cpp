

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int> map;
        vector<string> result;
        int n = words.size();

        for(char i : words[0])
            {
            if(!map.contains(i)) map[i] = 1;
            else map[i]++ ;
            }

        for(int i=1 ; i<n ; i++)
        {
            unordered_map<char,int> temp = map;
            for(char j:words[i])
            {
                if(map.contains(j)) temp[j]--;
            }
            for(pair j:temp)
            {
                if(j.second!=0 && j.second == map[j.first])
                    map.erase(j.first);
                else if (j.second < 0) 
                    continue;
                else if (j.second < map[j.first])
                    map[j.first]  -= j.second;
            }
        }

        for(pair i : map)
        {
            for(int k=0 ; k<i.second ; k++)
            {
                string j ; j += i.first;
                result.push_back(j);
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> words {"dadaabaa","bdaaabcc","abccddbb","bbaacdba","ababbbab","ccddbbba","bbdabbda","bdabaacb"};
    vector<string> result = sol.commonChars(words);
    for(string s : result)
        cout << s << " ";
    cout << endl;
    return 0;
}