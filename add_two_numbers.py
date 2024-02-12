"""
https://leetcode.com/problems/add-two-numbers/
"""
# Definition for singly-linked list.

from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    """
    Logic:
        Traverse both the linked list and add the values of the nodes.
        If the sum is greater than 9, then carry over the 1 to the next node.
        If one of the linked list is shorter than the other, then add 0 to the sum.
        If there is a carry over after the last node, then add a new node with value 1.
    """
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = None
        current = None
        carry = 0
        while l1 != None or l2 != None:
            sum = 0
            if l1:
                sum += l1.val
                l1 = l1.next
            if l2:
                sum += l2.val
                l2 = l2.next
            sum += carry
            if not head:
                head = ListNode((sum)%10,None)
                current = head
            else:
                ln = ListNode((sum)%10,None)
                current.next = ln
                current = ln
            if carry:
                carry = 0
            if sum > 9:
                carry = 1
        if carry:
            ln = ListNode(1,None)
            current.next = ln
            current = ln
        return head
        

class LinkedList:
    def __init__(self, head=None):
        self.head = head
        self.current = head
    
    def append(self, data):
        ll_node = ListNode(data,None)
        if self.current is None:
            self.current = self.head = ll_node
            
        else:
            self.current.next = ll_node
            self.current = ll_node
    
    def create(self,data:list):
        for i in data:
            self.append(i)
    
    def traverse(self,ln:ListNode = None):
        if ln:
            self.head = ln
        temp = self.head
        while temp != None:
            print(temp.val)
            temp = temp.next
    

if __name__ == '__main__':
    l1 = [2,4,3,9]
    l2 = [5,6,6]
    ll1 = LinkedList()
    ll1.create(l1)
    ll2 = LinkedList()
    ll2.create(l2)

    LinkedList().traverse(Solution().addTwoNumbers(ll1.head,ll2.head))