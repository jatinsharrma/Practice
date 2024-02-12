import unittest
from two_sum import Solution

class TestProb1(unittest.TestCase):
    def test_prob1(self):
        self.assertEqual(Solution().twoSum([2,7,11,15], 9), [0,1])

    def test_prob1_2(self):
        self.assertEqual(Solution().twoSum([3,2,4], 6), [1,2])

    def test_prob1_3(self):
        self.assertEqual(Solution().twoSum([3,3], 6), [0,1])
    
    def test_prob1_4(self):
        self.assertEqual(Solution().twoSum([3,2,3], 6), [0,2])

if __name__ == '__main__':
    unittest.main()

    