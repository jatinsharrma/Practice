import unittest
from substring_noduplicate import Solution

class TestProb3(unittest.TestCase):
    def test_prob3(self):
        self.assertEqual(Solution().lengthOfLongestSubstring("abcabcbb"), 3)
        self.assertEqual(Solution().lengthOfLongestSubstring("bbbbb"), 1)
        self.assertEqual(Solution().lengthOfLongestSubstring("pwwkew"), 3)
        self.assertEqual(Solution().lengthOfLongestSubstring(""), 0)
        self.assertEqual(Solution().lengthOfLongestSubstring(" "), 1)
        self.assertEqual(Solution().lengthOfLongestSubstring("au"), 2)
        self.assertEqual(Solution().lengthOfLongestSubstring("dvdf"), 3)
        self.assertEqual(Solution().lengthOfLongestSubstring("abba"), 2)
        self.assertEqual(Solution().lengthOfLongestSubstring("tmmzuxt"), 5)
        self.assertEqual(Solution().lengthOfLongestSubstring("tmmzuxt"), 5)
        self.assertEqual(Solution().lengthOfLongestSubstring("abcb"), 3)
        self.assertEqual(Solution().lengthOfLongestSubstring("aab"), 2)
        self.assertEqual(Solution().lengthOfLongestSubstring("dvdf"), 3)
        self.assertEqual(Solution().lengthOfLongestSubstring("ohvhjdml"), 6)
        self.assertEqual(Solution().lengthOfLongestSubstring("ohvhjdml"), 6)
        self.assertEqual(Solution().lengthOfLongestSubstring("ohvhjdml"), 6)
        self.assertEqual(Solution().lengthOfLongestSubstring("ohvhjdml"), 6)
        self.assertEqual(Solution().lengthOfLongestSubstring("ohvhjdml"), 6)
        self.assertEqual(Solution().lengthOfLongestSubstring("ohvhjdml"), 6)
        self.assertEqual(Solution().lengthOfLongestSubstring("ohvhjdml"), 6)
        self.assertEqual(Solution().lengthOfLongestSubstring("ohvhjdml"), 6)
        self.assertEqual(Solution().lengthOfLongestSubstring("ohvhjdml"), 6)

if __name__ == '__main__':
    unittest.main()
