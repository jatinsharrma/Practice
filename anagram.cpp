#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
    public:
        /**
         * Checks if two strings are anagrams of each other.
         * An anagram is a word or phrase formed by rearranging the letters of another word or phrase.
         * @param s The first string.
         * @param t The second string.
         * @return True if the strings are anagrams, false otherwise.
         */
        bool isAnagram(string s, string t)
        {
            if (s.size() != t.size()) return false;

            unordered_map<char,int> map;
            for(char i : s)
            {
                if (map.contains(i))
                {
                    map[i]++;
                }
                else 
                {
                    map[i] = 1;
                }
            }
            for(char i : t)
            {
                if (map.contains(i))
                {
                    if (map[i] == 0) return false;
                    map[i]--;
                }
                else
                {
                    return false;
                }
            }
            return true;

        }

        /**
         * Checks if two strings are anagrams of each other.
         * An anagram is a word or phrase formed by rearranging the letters of another word or phrase.
         * @param s The first string.
         * @param t The second string.
         * @return True if the strings are anagrams, false otherwise.
         */
        bool isAnagram2(string s, string t)
        {
            if (s.size() != t.size()) return false;

            sort(s.begin(),s.end());
            sort(t.begin(),t.end());
            if (s.compare(t) == 0)
                return true;
            return false;
        }
        
};

int test() {
    Solution solution;

    // Test case 1: Anagrams
    assert(solution.isAnagram("listen", "silent") == true);

    // Test case 2: Not anagrams (different lengths)
    assert(solution.isAnagram("hello", "world") == false);

    // Test case 3: Not anagrams (same lengths, different characters)
    assert(solution.isAnagram("abc", "def") == false);

    // Test case 4: Anagrams with repeated characters
    assert(solution.isAnagram("aab", "aba") == true);

    // Test case 5: Anagrams with special characters
    assert(solution.isAnagram("hello!", "!loleh") == true);

    std::cout << "All test cases passed!\n";

    return 0;
}

int main()
{
    Solution s;
    cout << s.isAnagram2("aadf","aadf");
    test();
    return 0;
}