import unittest
from add_two_numbers import Solution,LinkedList,ListNode

class TestProb2(unittest.TestCase):
    def test_prob2(self):
        l1 = LinkedList()
        l1.create([2,4,3])
        l2 = LinkedList()
        l2.create([5,6,4])
        node = Solution().addTwoNumbers(l1.head,l2.head)
        self.assertEqual(node.val,7)
        self.assertEqual(node.next.val,0)
        self.assertEqual(node.next.next.val,8)
    
    def test_prob2_2(self):
        l1 = LinkedList()
        l1.create([0])
        l2 = LinkedList()
        l2.create([0])
        node = Solution().addTwoNumbers(l1.head,l2.head)
        self.assertEqual(node.val,0)

    def test_prob2_3(self):
        l1 = LinkedList()
        l1.create([9,9,9,9,9,9,9])
        l2 = LinkedList()
        l2.create([9,9,9,9])
        node = Solution().addTwoNumbers(l1.head,l2.head)
        self.assertEqual(node.val,8)
        self.assertEqual(node.next.val,9)
        self.assertEqual(node.next.next.val,9)
        self.assertEqual(node.next.next.next.val,9)
        self.assertEqual(node.next.next.next.next.val,0)
        self.assertEqual(node.next.next.next.next.next.val,0)
        self.assertEqual(node.next.next.next.next.next.next.val,0)
        self.assertEqual(node.next.next.next.next.next.next.next.val,1)

    def test_prob2_4(self):
        l1 = LinkedList()
        l1.create([2,4,9])
        l2 = LinkedList()
        l2.create([5,6,4,9])
        node = Solution().addTwoNumbers(l1.head,l2.head)
        self.assertEqual(node.val,7)
        self.assertEqual(node.next.val,0)
        self.assertEqual(node.next.next.val,4)
        self.assertEqual(node.next.next.next.val,0)
        self.assertEqual(node.next.next.next.next.val,1)

    def test_prob2_5(self):
        l1 = LinkedList()
        l1.create([9,9,9,9,9,9,9])
        l2 = LinkedList()
        l2.create([0])
        node = Solution().addTwoNumbers(l1.head,l2.head)
        self.assertEqual(node.val,9)
        self.assertEqual(node.next.val,9)
        self.assertEqual(node.next.next.val,9)
        self.assertEqual(node.next.next.next.val,9)
        self.assertEqual(node.next.next.next.next.val,9)
        self.assertEqual(node.next.next.next.next.next.val,9)
        self.assertEqual(node.next.next.next.next.next.next.val,9)

if __name__ == '__main__':
    unittest.main()