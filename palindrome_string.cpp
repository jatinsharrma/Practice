// https://leetcode.com/problems/valid-palindrome/description/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Solution {
public:
    /**
     * Best solution
     * 
     * Checks if a given string is a palindrome.
     * A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward.
     * The function ignores non-alphanumeric characters and is case-insensitive.
     *
     * @param s The string to check for palindrome.
     * @return True if the string is a palindrome, false otherwise.
     */
    bool isPalindrome(string s) {
        int l=0,r=s.size()-1;
        
        while (l<r)
        {
            if (!iswalnum(s[l]))
            {
                l++;
                continue;
            }
            if (!iswalnum(s[r]))
            {
                r--;
                continue;
            }
            if(tolower(s[l]) != tolower(s[r]))
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    /**
     * Not a good solution as it takes more time to execute.
     * 
     * Checks if a given string is a palindrome.
     * A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward.
     * This function removes non-alphanumeric characters from the string, converts it to lowercase, and then checks if it is a palindrome.
     * @param s The string to be checked.
     * @return True if the string is a palindrome, false otherwise.
     */
    bool isPalindrome2(string s) {
        regex rp("[^[:alnum:]]");
        s = regex_replace(s,rp,"");
        for(int i=0 ; i <s.size() ; i++)
        {
            s[i] = tolower(s[i]);
        }
        int l=0,r=s.size()-1;
        while (l<=r)
        {
            if(s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};

int test() {
    Solution solution;

    // Test case 1: Empty string
    assert(solution.isPalindrome("") == true);

    // Test case 2: Single character
    assert(solution.isPalindrome("a") == true);

    // Test case 3: Palindrome with lowercase letters
    assert(solution.isPalindrome("racecar") == true);

    // Test case 4: Palindrome with mixed case letters
    assert(solution.isPalindrome("Able was I saw eLba") == true);

    // Test case 5: Non-palindrome with lowercase letters
    assert(solution.isPalindrome("hello") == false);

    // Test case 6: Non-palindrome with mixed case letters
    assert(solution.isPalindrome("Palindrome") == false);

    std::cout << "All test cases passed!" << std::endl;

    return 0;
}

int main()
{
    Solution s;
    cout << s.isPalindrome("a.");
    test();
    return 0;
}