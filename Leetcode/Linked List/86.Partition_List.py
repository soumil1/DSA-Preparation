# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        left, right = ListNode(), ListNode()
        tailLeft, tailRight = left, right

        while head:
            if head.val < x:
                tailLeft.next = head
                tailLeft = tailLeft.next
            else:
                tailRight.next = head
                tailRight = tailRight.next
            
            head = head.next

        tailLeft.next = right.next
        tailRight.next = None
        return left.next
        