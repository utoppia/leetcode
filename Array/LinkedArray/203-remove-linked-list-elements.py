# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def removeElements(self, head: ListNode, val: int) -> ListNode:
    p = ListNode(val + 1)
    p.next = head
    
    pos = p
    while pos:
      nt = pos.next
      while nt and (nt.val == val):
        nt = nt.next
      pos.next = nt
      pos = pos.next
    return p.next 
