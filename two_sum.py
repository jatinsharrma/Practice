"""
https://leetcode.com/problems/two-sum/
"""

class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        # O(n) time, O(n) space
        # Use a dictionary to store the difference and index
        # If the difference is in the dictionary, return the index
        # Else, store the difference and index in the dictionary
        diff_dict = {}
        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in diff_dict:
                return [diff_dict[diff], i]
            else:
                diff_dict[nums[i]] = i

    def twoSum2(self,nums:list[int],target:int) -> list[int]:
        # O(n^2) time, O(1) space
        # Brute force
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[i] + nums[j] == target:
                    return [i,j]
                
    def twoSum3(self,nums:list[int],target:int)->list[int]:
        new = sorted(nums)
        left = 0
        while left != len(new):
            right = left + 1
            while right != len(new):
                if new[left] + new[right] == target:
                    if new[left] == new[right]:
                        return [nums.index(new[left]),nums.index(new[right],nums.index(new[left])+1)]
                    return [nums.index(new[left]),nums.index(new[right])]
                if new[left] + new[right] > target:
                    break
                right += 1

print(Solution().twoSum3([3,3], 6))