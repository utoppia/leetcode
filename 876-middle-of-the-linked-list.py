# Definition for singly-linked list.
# class ListNode:
#   def __init__(self, val=0, next=None):
#     self.val = val
#     self.next = next
class Solution:
  def middleNode(self, head: ListNode) -> ListNode:
    n = 0
    p = head
    while p:
      n += 1
      p = p.next

    n //= 2
    while n:
      head = head.next
      n -= 1
    return head
