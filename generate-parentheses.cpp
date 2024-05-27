// https://leetcode.com/problems/generate-parentheses/
// https://neetcode.io/problems/generate-parentheses

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
vector<string> v;

public:
/**
 * Generates all valid combinations of parentheses with a given number of pairs.
 *
 * @param n The number of pairs of parentheses.
 * @return A vector of strings representing all valid combinations of parentheses.
 */
	vector<string> generateParenthesis1(int n) 
	{
		vector<string> result {"()"};

		for(int i=1 ; i<n ; i++)
		{
			this->printResult(result);
			set<string> set;

			for(string s:result)
			{
				set.insert(s+"()");
				set.insert("()"+s);
				for(int j=0 ; j<s.size()-1 ; j++)
				{
					set.insert(s.substr(0,j+1)+"()"+s.substr(j+1,s.size()));
				}

			}
			result = {};
			for (string s : set)
				result.push_back(s);

		}
		return result;
	}

/**
 * Prints the elements of a vector of strings.
 *
 * @param s The vector of strings to be printed.
 */
	void printResult(vector<string> s)
	{
		for(string i:s)
			cout << i << "    ";
		cout << endl << endl;
	}

    /**
     * Generates all valid combinations of parentheses given the number of open and close parentheses.
     * 
     * @param s The current combination of parentheses.
     * @param open The number of remaining open parentheses.
     * @param close The number of remaining close parentheses.
     */
    void bz(string &s, int open, int close)
    {
        if (open == 0 && close == 0)
        {
            v.push_back(s);
            cout << "open: " << open << " close: " << close << " s: " << s << endl;
            return;
        }
        if (open > 0)
        {
            s.push_back('(');
            bz(s, open - 1, close);
            s.pop_back();
            cout << "open: " << open << " close: " << close << " s: " << s << endl;
        }
        if (close > 0)
        {
            if (open < close)
            {
                s.push_back(')');
                bz(s, open, close - 1);
                s.pop_back();
                cout << "open: " << open << " close: " << close << " s: " << s << endl;
            }
        }
    }
    
    /**
     * Generates all valid combinations of parentheses with given number of pairs by calling bz function.
     * Better solution
     * 
     * @param n The number of pairs of parentheses.
     * @return A vector of strings representing all valid combinations of parentheses.
     */
    vector<string> generateParenthesis(int n) {
        string s;
        bz(s,n,n);
        return v;   
    }

};

int main()
{
	int n = 3;
	Solution s;
	vector<string> result =  s.generateParenthesis(n);
	for (string s : result)
		cout << s << endl;
	return 0;
}
