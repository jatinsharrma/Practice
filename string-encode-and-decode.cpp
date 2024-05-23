// https://neetcode.io/problems/string-encode-and-decode

// Problem
// You are given a vector of strings. Write a program to encode the vector of strings into a single string and decode the string back into the original vector of strings.

// Solution
// To encode the vector of strings, we can concatenate the length of each string followed by an underscore and the string itself. To decode the string, we can iterate through the string and extract the length of the string and the string itself.
// Underscore is added because string can be numbers and we need to differentiate between the length of the string and the string itself.

#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <cassert>

using namespace std;

/**
 * @class Solution
 * @brief Class that provides methods for encoding and decoding a vector of strings.
 */
class Solution
{
public:
	/**
	 * @brief Encodes a vector of strings into a single string.
	 * @param str The vector of strings to be encoded.
	 * @return The encoded string.
	 */
	string encode(vector<string>& str)
	{
		string s = "";
		for(string i : str)
		{
			int len = i.size();
			s += to_string(len)+"_" + i;
		}
		return s;
	}

	/**
	 * @brief Decodes a string into a vector of strings.
	 * @param s The string to be decoded.
	 * @return The decoded vector of strings.
	 */
	vector<string> decode(string s)
	{
		vector<string> str;
		string str_len = "";
		for(int i = 0 ; i < s.size() ;i++)
		{
			if (isdigit(s[i]))
			{
				str_len.push_back(s[i]);
				if (s[i] == '0' && str_len.size() == 1)
				{
					str.push_back("");
					str_len = "";
					i+=1;
				}
				continue;
			}

			int int_len = stoi(str_len);
			str.push_back(s.substr(i+1,int_len));
			i += int_len;
			str_len = "";
		}
		return str;
	}
};

/**
 * @brief Function to test the encode and decode functionality of the Solution class.
 * 
 * This function creates various test cases and verifies if the encoded and decoded strings are equal.
 * It uses the assert function to check the equality of the original and decoded strings.
 * If all the test cases pass, it prints "All test cases passed!".
 * 
 * @return int Returns 0 if all test cases pass.
 */
int test()
{
    Solution sol;

    // Test case 1: Empty vector
    {
        vector<string> str;
        string encoded = sol.encode(str);
        vector<string> decoded = sol.decode(encoded);
        assert(str == decoded);
    }

    // Test case 2: Vector with one empty string
    {
        vector<string> str {""};
        string encoded = sol.encode(str);
        vector<string> decoded = sol.decode(encoded);
        assert(str == decoded);
    }

    // Test case 3: Vector with multiple strings
    {
        vector<string> str {"abc", "defg", "hijkl"};
        string encoded = sol.encode(str);
        vector<string> decoded = sol.decode(encoded);
        assert(str == decoded);
    }

    // Test case 4: Vector with strings containing digits
    {
        vector<string> str {"123", "4567", "890"};
        string encoded = sol.encode(str);
        vector<string> decoded = sol.decode(encoded);
        assert(str == decoded);
    }

    // Test case 5: Vector with strings containing special characters
    {
        vector<string> str {"!@#$", "%^&*", "()_"};
        string encoded = sol.encode(str);
        vector<string> decoded = sol.decode(encoded);
        assert(str == decoded);
    }

    // Test case 6: Vector with strings of different lengths
    {
        vector<string> str {"a", "bb", "ccc", "dddd", "eeeee"};
        string encoded = sol.encode(str);
        vector<string> decoded = sol.decode(encoded);
        assert(str == decoded);
    }

    cout << "All test cases passed!\n";

    return 0;
}

int main()
{
	// Solution sol;
	// vector<string> str {""};
	// string s = sol.encode(str);
	// cout << s << "\n";
	// vector<string> new_str = sol.decode(s);
	// for(string i : new_str)
	// {
	// 	cout << i << endl;
	// }
	test();
	return 0;
}
