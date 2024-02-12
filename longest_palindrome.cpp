// https://leetcode.com/problems/longest-palindromic-substring/

/*
Logic 
    eg abaa
    1. We initially know length one strings are palindrome. So we make all digonals as one which represent length one string.

    this digonal represents 1 length palindrome
      |
    | /1/   | 0     | 0     | 0     |
    | 0     | /1/   | 0     | 0     |
    | 0     | 0     | /1/   | 0     |
    | 0     | 0     | 0     | /1/   |

    2. Now we see if two length strings are palindrome.  

            this digonal represents 2 length palindrome
                |
    | 1     | /0/   | 0     | 0     |
    | 0     | 1     | /0/   | 0     |
    | 0     | 0     | 1     | /2/   |
    | 0     | 0     | 0     | 1     |

    3. Now the dynamic part start. We know strings which are palindrome and have lenght 1 and two. Now when we are checking for length 3.
        we check if most significant character and least significant character are same and the intermediate string (for length 3 intermediate string length is 1)
        is palindome or not. if both satisfies we know current string is also a palindrome.

                    this digonal represents 3 length palindrome
                        |
    | 1     | 0     | /3/   | 0     |
    | 0     | 1     | 0     | /0/   |
    | 0     | 0     | 1     | 2     |
    | 0     | 0     | 0     | 1     |

                            this digonal represents 3 length palindrome
                               |
    | 1     | 0     | 3     | /0/   |
    | 0     | 1     | 0     | 0     |
    | 0     | 0     | 1     | 2     |
    | 0     | 0     | 0     | 1     |

    Note : I am only making correspoinding entery as true or false, for demostration i have used 1 2 3 numbers to show what legnth of palindrome I have matched at the point.

*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;
        bool arr[n][n];
        int max_len = 0;
        int start = 0;
        
        memset(arr,0,sizeof(arr));

        // for one length palindrome
        for (int i=0 ; i<n;i++)
        {
            arr[i][i] = true;
        }
        max_len=1;

        //for two length of palindrome
        for (int i=0; i<n-1 ; i++)
        {
            if(s[i] == s[i+1])
            {
                start = i;
                arr[i][i+1] = true;
                max_len=2;
            }
        }

        //for length > 2
        for(int k=3; k<=n; ++k)
        {
            for (int i=0 ; i<n-k+1; ++i)
            {
                int j = i+k-1;
                if(arr[i+1][j-1] && s[i] == s[j])
                {
                    arr[i][j] = true;
                    if (k>max_len)
                    {
                        start = i;
                        max_len = k;
                    }
                }
            }
        }
        
        string result = "";
        for (int i=start; i< start+max_len; i++)
        {
            result += s[i];
        }
        return result;
    }

    void test()
    {
        Solution solution;

        // Test Case 1: Palindrome in the middle
        std::string s1 = "babad";
        std::string expected1 = "bab";
        std::string result1 = solution.longestPalindrome(s1);
        assert(result1 == expected1);
        std::cout << "Test Case 1 Passed\n";

        // Test Case 2: Palindrome at the beginning
        std::string s2 = "cbbd";
        std::string expected2 = "bb";
        std::string result2 = solution.longestPalindrome(s2);
        assert(result2 == expected2);
        std::cout << "Test Case 2 Passed\n";

        // Test Case 3: Palindrome at the end
        std::string s3 = "racecar";
        std::string expected3 = "racecar";
        std::string result3 = solution.longestPalindrome(s3);
        assert(result3 == expected3);
        std::cout << "Test Case 3 Passed\n";

        // Test Case 4: Empty string
        std::string s4 = "";
        std::string expected4 = "";
        std::string result4 = solution.longestPalindrome(s4);
        assert(result4 == expected4);
        std::cout << "Test Case 4 Passed\n";

        // Test Case 5: Single character
        std::string s5 = "a";
        std::string expected5 = "a";
        std::string result5 = solution.longestPalindrome(s5);
        assert(result5 == expected5);
        std::cout << "Test Case 5 Passed\n";

        std::cout << "All test cases passed!\n";
    }

};

int main()
{
    Solution s;
    cout << s.longestPalindrome("abadd");
    s.test();
    return 0;
}