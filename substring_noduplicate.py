""" 
https://leetcode.com/problems/longest-substring-without-repeating-characters/
"""

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        """
        1. Create a dictionary to store the index of each character
        2. Iterate through the string
        3. If the character is in the dictionary, then update the max length. Start the index from the next character of the repeated character
        4. If the character is not in the dictionary, then add it to the dictionary
        5. Return the max length
        """
        max = 0
        index = 0
        current = 1
        if len(s) < 2:
            return len(s)
        dump = {s[0]:0}
        while current < len(s):
            if s[current] in dump:
                if max < (current - index):
                    max = current - index 
                index = dump[s[current]] + 1
                current = index 
                dump = {s[index]:index}
            else:
                dump[s[current]] = current
            current += 1
        if max < (current - index):
            max = (current - index) 
        return max

    def lengthOfLongestSubstring2(self, s: str) -> int:
        """
        1. Create a dictionary to store the index of each character
        2. Iterate through the string
        """
        start = result = 0
        seen = {}
        for i, letter in enumerate(s):
            if seen.get(letter, -1) >= start:
                start = seen[letter] + 1
            result = max(result, i - start + 1)
            seen[letter] = i
        return result

print(Solution().lengthOfLongestSubstring("pwwkew"))                