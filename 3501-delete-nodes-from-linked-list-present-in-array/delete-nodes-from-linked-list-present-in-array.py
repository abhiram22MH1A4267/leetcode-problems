# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        temp = ListNode(-1)
        temp1 = temp
        s = set(nums)
        
        while head:
            if head.val not in s:
                temp1.next = head
                temp1 = temp1.next
            head = head.next
        
        temp1.next = None
        return temp.next