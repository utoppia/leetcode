# Definition for singly-linked list.
# class ListNode:
#   def __init__(self, val=0, next=None):
#     self.val = val
#     self.next = next
class Solution:
  def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
    nodes = []
    p = head
    while p:
      nodes.append(p)
      p = p.next
    if len(nodes) == 0:
      return None

    n = (n-1) % len(nodes)
    n = len(nodes)-1-n
    if n == 0:
      return nodes[0].next
    if n == len(nodes) - 1:
      nodes[-2].next = None
      return nodes[0]
    nodes[n-1].next = nodes[n+1]
    return nodes[0]
