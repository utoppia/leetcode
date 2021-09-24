# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def deleteDuplicates(self, head: ListNode) -> ListNode:
    p = head
    while p:
      q = p.next
      while q and q.val == p.val:
        q = q.next

      p.next = q
      p = q
    return head
