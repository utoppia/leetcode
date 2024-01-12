# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
  def hasCycle(self, head: ListNode) -> bool:
    if not head:
      return False

    r = head.next # rabit who run fast
    t = head # tortoise who run slowly

    while r and t and  r != t:
      r = r.next
      if r:
        r = r.next
      t = t.next

    if not r:
      return False
    return True


        
