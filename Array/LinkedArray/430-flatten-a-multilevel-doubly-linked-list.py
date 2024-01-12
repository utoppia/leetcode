"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
  def flatten(self, head: 'Node') -> 'Node':
    if not head:
      return head

    child = head.child
    if not child:
      nxt = self.flatten(head.next)
      head.next = nxt
      if nxt:
        nxt.prev = head
      return head


    child = self.flatten(child)
    nxt = head.next
    head.next = child
    head.child = None
    child.prev = head
    while child.next:
      child = child.next
    nxt = self.flatten(nxt)
    child.next = nxt
    if nxt:
      nxt.prev = child
    return head

