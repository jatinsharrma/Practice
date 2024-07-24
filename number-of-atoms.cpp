/**
* @author Jatin Sharma
* @date 
* @problem
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        unordered_map<string,int> map;
        string atom = "";
        int count = 0;
        stack<pair<pair<string,int>,int>> st; 
        int flag = 0;
        int flag2 = 0;
        for(char c : formula)
        {
            if (c >= 65 && c<=90)
            {
                if(atom.length())
                {
                    if (flag2)
                    {
                        if(flag>1)
                        {
                            vector<pair<pair<string,int>,int>> temp;
                            while(!st.empty())
                            {
                                auto curr = st.top();
                                if(curr.second == flag)
                                {
                                    curr.second --;
                                    curr.first.second *= (count>0) ?count : 1;
                                    temp.push_back(curr);
                                    st.pop();
                                }
                                else break;
                            }
                            for(auto p : temp) st.push(p);
                        }
                        else 
                        {
                            while(!st.empty())
                            {
                                auto curr = st.top();
                                st.pop();

                                if(map.contains(curr.first.first)) map[curr.first.first] += curr.first.second * (count>0)?count:1;
                                else map[curr.first.first] = curr.first.second;
                            }
                        }
                        flag2--;
                        flag--;
                    }
                    else if (flag)
                    {
                        st.push({{atom,(count>0)?count:1},flag});
                    }
                    else
                    {
                        if(map.contains(atom)) map[atom] += (count>0)?count:1;
                        else map[atom] = (count>0)?count:1;
                    }
                }
                count = 0;
                atom = "";
                atom += c;
            }
            else if (c>=97 && c<=122)
            {
                atom += c;
            }
            else if (c>=48 && c<=57)
            {
                count *= 10;
                count += c - 48;
            }
            else if (c==40)
            {
                if (flag)
                {
                    st.push({{atom,(count>0)?count:1},flag});
                }
                else
                {
                    if(map.contains(atom)) map[atom] += (count>0)?count:1;
                    else map[atom] = (count>0)?count:1;
                }
                flag ++;
                count = 0;
                atom = "";
            }
            else if(c==41)
            {
                if (flag2)
                {
                    if(flag>1)
                    {
                        vector<pair<pair<string,int>,int>> temp;
                        while(!st.empty())
                        {
                            auto curr = st.top();
                            if(curr.second == flag)
                            {
                                curr.second --;
                                curr.first.second *= (count>0) ?count : 1;
                                temp.push_back(curr);
                                st.pop();
                            }
                            else break;
                        }
                        for(auto p : temp) st.push(p);
                    }
                    else 
                    {
                        while(!st.empty())
                        {
                            auto curr = st.top();
                            st.pop();

                            if(map.contains(curr.first.first)) map[curr.first.first] += curr.first.second;
                            else map[curr.first.first] = curr.first.second;
                        }
                    }
                    flag2--;
                    flag--;
                }
                flag2++;
                count = 0;
                atom = "";
            }
        }
       
        while(!st.empty())
        {
            auto curr = st.top();
            st.pop();

            if(map.contains(curr.first.first)) map[curr.first.first] += curr.first.second * (count>0)?count:1;
            else map[curr.first.first] = curr.first.second;
        }
                       
        if(atom.size())
        {
            if(map.contains(atom)) map[atom] += (count>0)?count:1;
            else map[atom] = (count>0)?count:1;
        }
        for(auto i: map)
            cout << i.first << " " << i.second << endl;
        return "";
    }
};

int main()
{
    Solution sol;
    return 0;
}