// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/?envType=daily-question&envId=2024-06-03

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	int appendCharacters(string s, string t)
	{
		int s_l = 0 , t_l = 0;
		int n = s.size();
		while(s_l < n)
		{
			if(s[s_l] == t[t_l])
				t_l ++;
			s_l++;
		}
		return t.size() - t_l;
	}
};

int main()
{
	Solution sol;
	string s = "abcde";
	string t = "a";
	cout << sol.appendCharacters(s,t) << endl;
	return 0;
}
